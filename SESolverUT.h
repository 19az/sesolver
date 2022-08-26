#ifndef SESOLVERUT_H
#define SESOLVERUT_H

/// @file SESolverUT.h

const int MAXNTESTSSE = 1e3;                    ///< max number of tests in unit test for se_solve()
const char tests_filename_se[] = "sesut.txt";   ///< name of the file with uint test for se_solve()
const int NARGSSE = 6;  
                                              
/// @brief Read 1 tests from the file with tests
///
/// @param[out] test array with args of test
/// @param[in] nArgs number of args in test
/// @param[in] test_filename name of the file with tests
///
/// @return 1 if EOF is reached, 0 otherwise
int read_test_file(double *test, int nArgs, const char *test_filename);

/// @brief Runs 1 test from unit test for se_solve()
///
/// @param[in] test array of args of test
/// @param[out] nRoots pointer to the number of roots result
/// @param[out] root1 pointer to the 1st root result
/// @param[out] root2 pointer to the 2nd root result
///
/// @return 1 if test is passed, 0 otherwise
int run_test_se(double *test, int* nRoots, double *root1, double *root2);

/// @brief Unit test for se_solve()
///
/// @note Shows report after tests using unit_test_report()
void se_solve_ut();

/// @brief Runs 1 test from unit test for le_solve()
///
/// @param[in] test array of args of test
/// @param[out] nRoots pointer to the number of roots result
/// @param[out] root1 pointer to the 1st root result
///
/// @return 1 if test is passed, 0 otherwise
int run_test_se(double *test, int* nRoots, double *root1);

/// @brief Unit test for le_solve()
/// 
/// @note Shows report after tests using unit_test_report()
void le_solve_ut();

/// @brief Shows report after unit test
///
/// @param[in] tests  array of results of unit tests
void unit_test_report(int* testsnTests);


#endif /* SESOLVER_H */
