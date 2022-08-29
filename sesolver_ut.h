#ifndef SESOLVER_UT_H
#define SESOLVER_UT_H

/// @file sesolver_ut.h

const int MAXNTESTS_SE     = 1e2;             ///< max number of tests in unit test for se_solve()
const int MAXBUFFERSIZE_SE = 1e3;             ///< max len of file with unit test for se_solve()
const char tests_filename_se[] = "sesut.txt"; ///< name of the file with uint test for se_solve()

/// struct for return codes for read_tests_file()
enum retcode_rf {              
                 FILE_ERR = 1, ///< cannot open file
                 SIZE_ERR = 2  ///< buffer too small
                 };

/// Struct to represent arguments for unit test for se_solve()
struct SETestArgs {
    double a;      ///< 1st coef
    double b;      ///< 2nd coef
    double c;      ///< 3rd coef
    int nRoots;    ///< number of roots
    double root1;  ///< 1st root
    double root2;  ///< 2nd root
};

/// Struct to represent arguments for unit test for le_solve()
struct LETestArgs {
    double a;       ///< 1ts coef
    double b;       ///< 2nd coef
    int nRoots;     ///< number of roots
    double root;    ///< root
};
                                              
/// @brief Gets one test from buffer
///
/// @param[out] test pointer to struct with args
/// @param[in] buffer buffer with text
///
/// @return number of read bytes, 
/// -1 if EOF is reached
int get_one_test_se(SETestArgs *test, const char *buffer);

/// @brief Runs 1 test from unit test for se_solve()
///
/// @param[in] test pointer to struct with args
/// @param[out] nRoots pointer to the number of roots result
/// @param[out] root1 pointer to the 1st root result
/// @param[out] root2 pointer to the 2nd root result
///
/// @return 1 if test is passed,
/// 0 otherwise
int run_test_se(SETestArgs *test, int* nRoots, double *root1, double *root2);

/// @brief Unit test for se_solve()
///
/// @note Shows report after tests using unit_test_report()
void se_solve_ut();

/// @brief Runs 1 test from unit test for le_solve()
///
/// @param[in] test pointer to struct with args
/// @param[out] nRoots pointer to the number of roots result
/// @param[out] root1 pointer to the 1st root result
///
/// @return 1 if test is passed, 0 otherwise
int run_test_le(LETestArgs *test, int* nRoots, double *root1);

/// @brief Unit test for le_solve()
/// 
/// @note Shows report after tests using unit_test_report()
void le_solve_ut();

/// @brief Shows report after unit test
///
/// @param[in] tests  array of results of unit tests
void unit_test_report(int* testsnTests);


#endif /* SESOLVER_UT_H */
