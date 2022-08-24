/// @file SESolver.c

#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "SESolver.h"

int se_solve(double a, double b, double c, double *root1, double *root2) {
    assert(root1 != NULL);
    assert(root2 != NULL);
    assert(root1 != root2);

    if (!std::isfinite(a) || !std::isfinite(b) || !std::isfinite(c)) {
        return ERR;
    }

    int nRoots = 0;
    if (is_equal(a, 0)) {
        if (is_equal(b, 0)) {
            nRoots = (is_equal(c, 0)) ? INF : 0;
        } else {
            *root1 = -c/b;
            nRoots = 1;
        }
    } else {
        if (is_equal(b, 0)) {
            if (is_equal(c, 0)) {
                *root1 = 0;
                nRoots = 1;
            } else {
                double squared_x = -c/a;
                if (squared_x > 0) {
                    *root1 = -sqrt(squared_x);
                    *root2 = -*root1;
                    nRoots = 2;
                } else {
                    nRoots = 0;
                }
            }
        } else {
            if (is_equal(c, 0)) {
                *root1 = 0;
                *root2 = -b/a;
                if (*root1 > *root2) {
                    double swap = *root1;
                    *root1 = *root2;
                    *root2 = swap;
                } 
                nRoots = 2;
            } else {
                double squared_discr = b*b - 4*a*c;
                if (squared_discr < 0) {
                    nRoots = 0;
                } else if (is_equal(squared_discr, 0)) {
                    *root1 = -b/(2*a);
                    nRoots = 1;
                } else {
                    double discr = sqrt(squared_discr);
                    *root1 = (-b - discr)/(2*a);
                    *root2 = (-b + discr)/(2*a);
                    nRoots = 2;
                }
            }
        }
    }

    return nRoots;
}

int is_equal(double a, double b) {
    return (fabs(a - b) < EPS);
}
