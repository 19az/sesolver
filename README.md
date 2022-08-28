# SESolver
Square eqution solver for MIPT summer school 2022
## Description
Solves equation $Ax^{2} + Bx + C = 0$ where $A, B, C$ double values
## Signature
    
    int se_solve(double a, double b, double c, double *root1, double *root2);
## Input
a, b, c; - coefficients of equation<br>
root1, root2; - roots of equation
## Return value
nRoots - number of roots
## Example
    
    ...
    double root1, root2;
    int nRoots = se_solve(1, 3, 2, &root1, &root2);
    printf("%d %lg %lg\n", nRoots, root1, root2);

Result:

    2 -2 -1
## Launch
For launching

    make
    ./SESolver
## Unit test
For launching with unit tests

    make ut
    ./SESolver
