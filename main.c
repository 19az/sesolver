#include <assert.h>
#include <stdio.h>
#include <math.h>

#include "SESolver.h"
#include "SESolverUT.h"

int main() {
#ifdef SEUT
    se_solve_ut();
#endif
#ifdef LEUT
    le_solve_ut();
#endif
    printf("Square equation solver\n");

    double a = NAN;
    double b = NAN;
    double c = NAN;
    printf("Enter coefficients of equation: a b c\n");
    while (scanf("%lg %lg %lg", &a, &b, &c) != 3) {
        printf("Error. Wrong type of data\n");
        int ch = 0;
        while ((ch = getchar()) != '\n') {
            assert(("EOF is read", ch != -1));
        }
        printf("Try again:\n");
    }

    double root1 = NAN;
    double root2 = NAN;
    int nRoots = se_solve(a, b, c, &root1, &root2);

    switch(nRoots) {
        case 0:   printf("Equation has no roots\n");
                  break;

        case 1:   printf("Equation has 1 root: %lg\n", root1);
                  break;

        case 2:   printf("Equation has 2 roots: %lg, %lg\n", root1, root2);
                  break;

        case INF: printf("Any number is a root\n");
                  break;

        case ERR: printf("Some of coefficients are not finite\n");
                  break;

        default:  printf("Error. Equaiton has %d roots\n", nRoots);
                  return 1;
    }

    return 0;
}
