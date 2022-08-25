/// @file SESolverUT.c

#define RED(x)             \
printf("\033[1;31m");      \
x                          \
printf("\033[0m");         
              
#define GREEN(x)           \
printf("\033[0;32m");      \
x                          \
printf("\033[0m");         

#include <math.h>
#include <stdio.h>

#include "SESolverUT.h"
#include "SESolver.h"

void se_solve_ut() {
    printf("\nUnit test for se_solve()\n");

    const int nTests = 14;
                             //    a         b              c   nr   r1   r2
    double tests[nTests][6] = {{   0,        0,             0, INF,   0,   0}, // 0
                               {   0,        0,             1,   0,   0,   0}, // 1
                               {   0,        1,             0,   1,   0,   0}, // 2
                               {   1,        0,             0,   1,   0,   0}, // 3
                               {   0,        1,             1,   1,  -1,   0}, // 4
                               {   1,        0,             1,   0,   0,   0}, // 5
                               {   1,        0,            -1,   2,  -1,   1}, // 6
                               {   1,        1,             0,   2,  -1,   0}, // 7
                               {   1,        1,             1,   0,   0,   0}, // 8
                               {   1,        2,             1,   1,  -1,   0}, // 9
                               {   1,        3,             2,   2,  -2,  -1}, // 10
                               { NAN,        0,             0, ERR,   0,   0}, // 11
                               {   0, INFINITY,             0, ERR,   0,   0}, // 12
                               {   0,        0, std::exp(800), ERR,   0,   0}  // 13
                              };

    int results[nTests] = {};
    double root1 = NAN;
    double root2 = NAN;
    for (int i = 0; i < nTests; ++i) {
        printf("Test # %d ... ", i);

        root1 = root2 = 0;
        int nRoots = se_solve(tests[i][0], tests[i][1], tests[i][2], &root1, &root2);
        int result = 1;
        if (nRoots == tests[i][3]) {
            if (nRoots == 1) {
                result = (is_equal(root1, tests[i][4]));
            }
            if (nRoots == 2) {
                result = (is_equal(root1, tests[i][4]) && is_equal(root2, tests[i][5]));
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
                   "nRoots(res) = %lg\n"
                   "root1(res)  = %lg\n"
                   "root2(res)  = %lg\n",
                   tests[i][0],
                   tests[i][1],
                   tests[i][2],
                   tests[i][3],
                   tests[i][4],
                   tests[i][5],
                   nRoots,
                   root1,
                   root2);
        }
    }
    unit_test_report(results, nTests);
    printf("Unit test is over\n\n");
}

void le_solve_ut() {
    printf("\nUnit test for le_solve()\n");

    const int nTests = 4;
                             // a  b   nr   r
    double tests[nTests][4] = {{0, 0, INF,  0}, // 0
                               {0, 1,   0,  0}, // 1
                               {1, 0,   1,  0}, // 2
                               {1, 1,   1, -1}, // 3
                              };

    int results[nTests] = {};
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
                   "root(exp)  = %lg\n"
                   "nRoots(res) = %lg\n"
                   "root(res)  = %lg\n",
                   tests[i][0],
                   tests[i][1],
                   tests[i][2],
                   tests[i][3],
                   nRoots,
                   root);
        }
    }
    unit_test_report(results, nTests);
    printf("Unit test is over\n\n");
}


void unit_test_report(int *tests, int nTests) {
    RED(printf("Failed tests numbers: ");)
    for (int i = 0; i < nTests; ++i) {
        if (!tests[i]) {
            RED(printf("%d ", i);)
        }
    }
    printf("\n");
}
