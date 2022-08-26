/// @file SESolverUT.c

#define RED(x)             \
printf("\033[1;31m");      \
x                          \
printf("\033[0m");         
              
#define GREEN(x)           \
printf("\033[0;32m");      \
x                          \
printf("\033[0m");         

#define YELLOW(x)          \
printf("\033[0;33m");      \
x                          \
printf("\033[0m");         

#include <math.h>
#include <stdio.h>

#include "SESolverUT.h"
#include "SESolver.h"

void se_solve_ut() {
    YELLOW(printf("\nUnit test for se_solve()\n");)

    const char *tests_filename = "sesut.txt";
    FILE *tests_file = fopen(tests_filename, "r");
    double test[6] = {};

    int results[MAXNTESTS] = {};
    double root1 = NAN;
    double root2 = NAN;
    for (int i = 0; ; ++i) {
        if (fscanf(tests_file,
               "%lg %lg %lg %lg %lg %lg",
               test, test+1, test+2, test+3, test+4, test+5) == EOF) {
            results[i] = -1;
            break;
        }
        printf("Test # %2d ... ", i);

        root1 = root2 = 0;
        int nRoots = se_solve(test[0], test[1], test[2], &root1, &root2);
        int result = 1;
        if (nRoots == test[3]) {
            if (nRoots == 1) {
                result = (is_equal(root1, test[4]));
            }
            if (nRoots == 2) {
                result = (is_equal(root1, test[4]) && is_equal(root2, test[5]));
            }
        } else {
            result = 0;
        }
        results[i] = result;
        if (result) {
            GREEN(printf("OK\n");)
        } else {
            RED(printf("FAILED\n");)
            printf("a           = %lg\n"
                   "b           = %lg\n"
                   "c           = %lg\n"
                   "nRoots(exp) = %lg\n"
                   "root1(exp)  = %lg\n"
                   "root2(exp)  = %lg\n"
                   "nRoots(res) = %d\n"
                   "root1(res)  = %lg\n"
                   "root2(res)  = %lg\n",
                   test[0],
                   test[1],
                   test[2],
                   test[3],
                   test[4],
                   test[5],
                   nRoots,
                   root1,
                   root2);
        }
    }
    unit_test_report(results);
    fclose(tests_file);
    YELLOW(printf("Unit test is over\n\n");)
}

void le_solve_ut() {
    YELLOW(printf("\nUnit test for le_solve()\n");)

    const int nTests = 4;
                             // a  b   nr   r
    double tests[nTests][4] = {{0, 0, INF,  0}, // 0
                               {0, 1,   0,  0}, // 1
                               {1, 0,   1,  0}, // 2
                               {1, 1,   1, -1}, // 3
                              };

    int results[nTests + 1] = {};
    double root = NAN;
    for (int i = 0; i < nTests; ++i) {
        printf("Test # %d ... ", i);

        root = 0;
        int nRoots = le_solve(tests[i][0], tests[i][1], &root);
        int result = 1;
        if (nRoots == tests[i][2]) {
            if (nRoots == 1) {
                result = (is_equal(root, tests[i][3]));
            }
        } else {
            result = 0;
        }
        results[i] = result;
        if (result) {
            GREEN(printf("OK\n");)
        } else {
            RED(printf("FAILED\n");)
            printf("a           = %lg\n"
                   "b           = %lg\n"
                   "nRoots(exp) = %lg\n"
                   "root(exp)   = %lg\n"
                   "nRoots(res) = %d\n"
                   "root(res)   = %lg\n",
                   tests[i][0],
                   tests[i][1],
                   tests[i][2],
                   tests[i][3],
                   nRoots,
                   root);
        }
    }
    results[4] = -1;
    unit_test_report(results);
    YELLOW(printf("Unit test is over\n\n");)
}


void unit_test_report(int *tests) {
    RED(printf("Failed tests numbers: ");)
    for (int i = 0; tests[i] != -1 && i < MAXNTESTS; ++i) {
        if (!tests[i]) {
            RED(printf("%d ", i);)
        }
    }
    printf("\n");
}
