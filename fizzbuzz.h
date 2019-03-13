//
// Created by Fedya on 2019-03-13.
//

#ifndef FIZZBUZZ_FIZZBUZZ_H
#define FIZZBUZZ_FIZZBUZZ_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <memory.h>

enum {
    MAXIMUM_LENGTH = 40000000,
    FIZZ = 3,
    BUZZ = 5,
    FIZZBUZZ = FIZZ * BUZZ,
    PIZDEC = -1
};


int inner_fizzbuzz(char * str);
int fizzbuzz(char *str);

#endif //FIZZBUZZ_FIZZBUZZ_H
