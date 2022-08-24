#include <stdio.h>
#include <math.h>

#include "SESolver.h"
#include "SESolverUT.h"

const int UT = 1;

int main() {
    printf("Square equation solver\n");

    if (UT) {
        se_solve_ut();
    }

    double a = 0;
    double b = 0;
    double c = 0;
    printf("Enter coefficients of equation: a b c\n");
    while (scanf("%lg %lg %lg", &a, &b, &c) != 3) {
        printf("Error. Wrong type of data\n");
        while (getchar() != '\n');
        printf("Try again:\n");
    }

    double root1 = 0;
    double root2 = 0;
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
