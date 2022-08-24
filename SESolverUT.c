/// @file SESolverUT.c

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
    double root1 = 0;
    double root2 = 0;
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
            printf("OK\n");
        } else {
            printf("FAILED\n");
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

void unit_test_report(int *tests, int nTests) {
    printf("Failed tests numbers: ");
    for (int i = 0; i < nTests; ++i) {
        if (!tests[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
