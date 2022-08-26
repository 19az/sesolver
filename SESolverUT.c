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

#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "SESolverUT.h"
#include "SESolver.h"

int read_test_file(double *test, int nArgs, const char *tests_filename) {
    static int open = 0;
    static FILE *tests_file = NULL;
    if (!open) {
        open = 1;
        tests_file = fopen(tests_filename, "r");
        assert(("Cannot open file", tests_file != NULL));
    }

    int end_of_file = 0;
    for (int i = 0; i < nArgs; ++i) {
        if (fscanf(tests_file, "%lg", test + i) == EOF) {
            end_of_file = 1;
            break;
        }
    }

    if (end_of_file) {
        fclose(tests_file);
    }
    return end_of_file;
}

int run_test_se(double *test, int *nRoots, double *root1, double *root2) {
    *nRoots = se_solve(test[0], test[1], test[2], root1, root2);
    int result = 1;
    if (*nRoots == test[3]) {
        if (*nRoots == 1) {
            result = (is_equal(*root1, test[4]));
        }
        if (*nRoots == 2) {
            result = (is_equal(*root1, test[4]) && is_equal(*root2, test[5]));
        }
    } else {
        result = 0;
    }

    return result;
}

void se_solve_ut() {
    YELLOW(printf("\nUnit test for se_solve()\n");)

    double test[NARGSSE] = {};
    int results[MAXNTESTSSE];
    for (int i = 0; ; ++i) {
        if (read_test_file(test, NARGSSE, tests_filename_se)) {
            results[i] = -1;
            break;
        } 
        printf("Test # %2d ... ", i);

        int nRoots = 0;
        double root1 = NAN;
        double root2 = NAN;
        results[i] = run_test_se(test, &nRoots, &root1, &root2);

        if (results[i]) {
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
    YELLOW(printf("Unit test is over\n\n");)
}

int run_test_le(double *test, int *nRoots, double *root) {
    *nRoots = le_solve(test[0], test[1], root);
    int result = 1;
    if (*nRoots == test[2]) {
        if (*nRoots == 1) {
            result = (is_equal(*root, test[3]));
        }
    } else {
        result = 0;
    }

    return result;
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
    for (int i = 0; i < nTests; ++i) {
        printf("Test # %d ... ", i);

        int nRoots = 0;
        double root = NAN;
        results[i] = run_test_le(tests[i], &nRoots, &root);

        if (results[i]) {
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
    for (int i = 0; tests[i] != -1; ++i) {
        if (!tests[i]) {
            RED(printf("%d ", i);)
        }
    }
    printf("\n");
}
