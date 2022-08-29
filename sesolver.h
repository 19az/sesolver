#ifndef SESOLVER_H
#define SESOLVER_H

/// @file SESolver.h

const double EPS = 1e-10; ///< Precision of equality of two numbers
enum retcode_se {            ///< Return codes for se_solve():
                 INF = -1,   ///< INF - infinite number of roots
                 COEF = -2,  ///< COEF - some coefficients are not finite
                 ROOT = -3}; ///< ROOT - bad pointers to roots
                                                        
                                                        
                                                        

/// @brief Solves square equation
/// 
/// @param[in]  a     1st coef
/// @param[in]  b     2nd coef
/// @param[in]  c     3rd coef
/// @param[out] root1 pointer to the 1st root
/// @param[out] root2 pointer to the 2nd root
///
/// @return number of roots of equation
int se_solve(double a, double b, double c, double *root1, double *root2);

/// @brief Checks if two double numbers are equal
/// 
/// @param[in] a 1st double number
/// @param[in] b 2nd double number
///
/// @return 1 if equal and 0 otherwise
///
/// @note uses EPS as valid precision
int is_equal(double a, double b);

/// @brief Swaps two double numbers
///
/// @param[in] a pointer to the 1st number
/// @param[in] b pointer to the 2nd number
void swap(double *a, double *b);

/// @brief Solves linear equation
///
/// @param[in]  a    1st coef
/// @param[in]  b    2nd coef
/// @param[out] root pointer to the root
int le_solve(double a, double b, double *root);

#endif /* SESOLVER_H */