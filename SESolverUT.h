#ifndef SESOLVERUT_H
#define SESOLVERUT_H

/// @file SESolverUT.h

const int MAXNTESTS_SE     = 1e3;             ///< max number of tests in unit test for se_solve()
const int MAXBUFFERSIZE_SE = 1e5;             ///< max len of file with unit test for se_solve()
const char tests_filename_se[] = "sesut.txt"; ///< name of the file with uint test for se_solve()
enum retcode_rtf {                ///< return codes for read_tests_file()
                   FILE_ERR = 1}; /// FILE_ERR - cannot open file

/// @struct SETestArgs
///
/// @brief Struct for arguments of unit test for se_solve()
/// 
/// @var SETestArgs::a 1ts coef
/// @var SETestArgs::b 2nd coef
/// @var SETestArgs::c 3rd coef
/// @var SETestArgs::nRoots number of roots
/// @var SETestArgs::root1 1st root
/// @var SETestArgs::root2 2nd root
struct SETestArgs {
    double a, b, c;
    int nRoots;
    double root1, root2;
};

/// @struct LETestArgs
///
/// @brief Struct for arguments of unit test for le_solve()
/// 
/// @var SETestArgs::a 1ts coef
/// @var SETestArgs::b 2nd coef
/// @var SETestArgs::nRoots number of roots
/// @var SETestArgs::root 1st root
struct LETestArgs {
    double a, b;
    int nRoots;
    double root;
};
                                              
/// @brief Reads file into buffer
///
/// @param[in] filename name of the file
/// @param[out] buffer buffer for text
int read_file(const char *filename, char *buffer);

/// @brief Gets one test from buffer
///
/// @param[out] test pointer to struct with args
/// @param[in] buffer buffer with text
///
/// @return number of read bytes, -1 if EOF is reached
int get_one_test_se(SETestArgs *test, const char *buffer);

/// @brief Runs 1 test from unit test for se_solve()
///
/// @param[in] test pointer to struct with args
/// @param[out] nRoots pointer to the number of roots result
/// @param[out] root1 pointer to the 1st root result
/// @param[out] root2 pointer to the 2nd root result
///
/// @return 1 if test is passed, 0 otherwise
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


#endif /* SESOLVERUT_H */
