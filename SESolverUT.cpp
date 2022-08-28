/// @file SESolverUT.c

#define RED(x)             \
printf("\033[1;31m");      \
x                          \
printf("\033[0m");         
              
#define GREEN(x)           \
printf("\033[0;32m");      \
x                          \
printf("\033[0m");         

#define YELLOW(x)          \
printf("\033[0;33m");      \
x                          \
printf("\033[0m");         

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "SESolverUT.h"
#include "SESolver.h"

int read_file(const char *filename, char *buffer, size_t *file_size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        enum retcode_rf ret = FILE_ERR;
        return ret;
    }
        
    fseek(file, 0, SEEK_END);
    *file_size = ftell(file);
    if (*file_size > MAXBUFFERSIZE_SE) {
        enum retcode_rf ret = SIZE_ERR;
        return ret;
    }
    fseek(file, 0, SEEK_SET);
    fread(buffer, *file_size, 1, file);

    fclose(file);
    return 0;
}

int get_one_test_se(SETestArgs *test, const char *buffer) {
    int bytes_read = 0;
    int end_of_file = sscanf(buffer,
                             "%lg %lg %lg %d %lg %lg %n",
                              &test->a,
                              &test->b,
                              &test->c,
                              &test->nRoots,
                              &test->root1,
                              &test->root2,
                              &bytes_read);

    if (end_of_file == EOF) {
        return -1;
    } else {
        return bytes_read;
    }
}

int run_test_se(SETestArgs *test, int *nRoots, double *root1, double *root2) {
    *nRoots = se_solve(test->a, test->b, test->c, root1, root2);
    int result = 1;
    if (*nRoots == test->nRoots) {
        if (*nRoots == 1) {
            result = (is_equal(*root1, test->root1));
        }
        if (*nRoots == 2) {
            result = (is_equal(*root1, test->root1) && is_equal(*root2, test->root2));
        }
    } else {
        result = 0;
    }

    return result;
}

void se_solve_ut() {
    YELLOW(printf("\nUnit test for se_solve()\n");)

    char buffer[MAXBUFFERSIZE_SE];
    size_t file_size = 0;
    if (read_file(tests_filename_se, buffer, &file_size) != 0) {
        printf("Error occured during reading file\n");
        return;
    }
    buffer[file_size] = '\n';
    buffer[file_size + 1] = '\0';

    SETestArgs test  = {};
    int results[MAXNTESTS_SE];
    int bytes_read = 0;
    char *buffer_ptr = buffer;
    for (int i = 0; (bytes_read = get_one_test_se(&test, buffer_ptr)) != -1; ++i) {
        buffer_ptr += bytes_read;
        printf("Test # %2d ... ", i);

        int nRoots = 0;
        double root1 = NAN;
        double root2 = NAN;
        results[i] = run_test_se(&test, &nRoots, &root1, &root2);
        results[i + 1] = -1;

        if (results[i]) {
            GREEN(printf("OK\n");)
        } else {
            RED(printf("FAILED\n");)
            printf("a           = %lg\n"
                   "b           = %lg\n"
                   "c           = %lg\n"
                   "nRoots(exp) = %d\n"
                   "root1(exp)  = %lg\n"
                   "root2(exp)  = %lg\n"
                   "nRoots(res) = %d\n"
                   "root1(res)  = %lg\n"
                   "root2(res)  = %lg\n",
                   test.a,
                   test.b,
                   test.c,
                   test.nRoots,
                   test.root1,
                   test.root2,
                   nRoots,
                   root1,
                   root2);
        }
    }
    unit_test_report(results);
    YELLOW(printf("Unit test is over\n\n");)
}

int run_test_le(LETestArgs *test, int *nRoots, double *root) {
    *nRoots = le_solve(test->a, test->b, root);
    int result = 1;
    if (*nRoots == test->nRoots) {
        if (*nRoots == 1) {
            result = (is_equal(*root, test->root));
        }
    } else {
        result = 0;
    }

    return result;
}

void le_solve_ut() {
    YELLOW(printf("\nUnit test for le_solve()\n");)

    const int nTests = 4;
                              // a  b  nr   r
    LETestArgs tests[nTests] = {{0, 0, -1,  0}, // 0
                                {0, 1,  0,  0}, // 1
                                {1, 0,  1,  0}, // 2
                                {1, 1,  1, -1}, // 3
                               };

    int results[nTests + 1] = {};
    for (int i = 0; i < nTests; ++i) {
        printf("Test # %d ... ", i);

        int nRoots = 0;
        double root = NAN;
        results[i] = run_test_le(tests + i, &nRoots, &root);

        if (results[i]) {
            GREEN(printf("OK\n");)
        } else {
            RED(printf("FAILED\n");)
            printf("a           = %lg\n"
                   "b           = %lg\n"
                   "nRoots(exp) = %d\n"
                   "root(exp)   = %lg\n"
                   "nRoots(res) = %d\n"
                   "root(res)   = %lg\n",
                   tests[i].a,
                   tests[i].b,
                   tests[i].nRoots,
                   tests[i].root,
                   nRoots,
                   root);
        }
    }
    results[4] = -1;
    unit_test_report(results);
    YELLOW(printf("Unit test is over\n\n");)
}


void unit_test_report(int *tests) {
    RED(printf("Failed tests numbers: ");)
    for (int i = 0; tests[i] != -1; ++i) {
        if (!tests[i]) {
            RED(printf("%d ", i);)
        }
    }
    printf("\n");
}
