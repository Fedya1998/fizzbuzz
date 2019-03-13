//
// Created by Fedya on 2019-03-13.
//

#include "fizzbuzz.h"

int fizzbuzz(char *str) {

    int ret = 1;
    ret *= inner_fizzbuzz(str);
    if (ret != PIZDEC && (str[strlen(str) - 1] == '0' || str[strlen(str) - 1] == '5')) {
        ret *= BUZZ;
    }
    return ret;
}

int inner_fizzbuzz(char * str) {
    int div_by_3 = 0;
    char new_str[20] = "";
    if (strlen(str) > MAXIMUM_LENGTH){
        errno = E2BIG;
        return PIZDEC;
    }
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] < '0' || str[i] > '9') {
            errno = EINVAL;
            return PIZDEC;
        }
        div_by_3 += str[i] - '0';
    }
    if (div_by_3 < 10) {
        if (div_by_3 == 0 || div_by_3 == 3 || div_by_3 == 6 || div_by_3 == 9)
            return FIZZ;
        else
            return 1;
    }
    sprintf(new_str, "%i", div_by_3);
    return inner_fizzbuzz(new_str);
}


int fizzbuzz_test(char * str) {
    return 0;
}

int inner_fizzbuzz_test(char * str) {
    return 0;
}