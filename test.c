//
// Created by Fedya on 2019-03-13.
//

#include "fizzbuzz.h"

#define TESTS_NUMBER 7

typedef struct test {
    char * str;
    int ret;
    int error;
} test;

int main(int argc, char ** argv) {
    char f[] = "fizz";
    char b[] = "buzz";
    char fb[] = "fizzbuzz";

    char * super_string = malloc(MAXIMUM_LENGTH + 1);
    memset(super_string, '1', MAXIMUM_LENGTH + 1);
    test tests[TESTS_NUMBER] = {
            {"1", 1, 0},
            {"3", FIZZ, 0},
            {"15", BUZZ * FIZZ, 0},
            {"27", FIZZ, 0},
            {"279", FIZZ, 0},
            {super_string, PIZDEC, E2BIG},
            {"2R", PIZDEC, EINVAL}
    };

    int successful_tests = 0;
    char str[20] = "";
    for (int i = 0; i < TESTS_NUMBER; i++) {
        if (tests[i].str == super_string)
            printf("Testing a rather massive string... ");
        else
            printf("Testing %s... ", tests[i].str);

        int ret = fizzbuzz(tests[i].str);

        if (ret != tests[i].ret || errno != tests[i].error)
            printf("Failed!\n");
        else {
            printf("Passed!\n");
            successful_tests++;
        }
    }

    printf("Tested, passed %d tests of %d\n", successful_tests, TESTS_NUMBER);
    return successful_tests;
}
