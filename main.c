#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <memory.h>


const int FIZZ = 3;
const int BUZZ = 5;
const int FIZZBUZZ = FIZZ * BUZZ;
const int PIZDEC = -1;

int inner_fizzbuzz(char * str);
int wrapper_fizzbuzz(char * str);

int wrapper_fizzbuzz(char * str) {
	
	int ret = 1;
	ret *= inner_fizzbuzz(str);
	if (str[strlen(str) - 1] == '0' || str[strlen(str) - 1] == '5') {
        ret *= BUZZ;
    }
	return ret;
}

int inner_fizzbuzz(char * str) {
	int div_by_3 = 0;
	char new_str[20] = "";
	if (strlen(str) > 4e10) {
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

int main(int argc, char ** argv) {
	char f[] = "fizz";
	char b[] = "buzz";
	char fb[] = "fizzbuzz";
	for(int i = 1; i < argc; i++) {
		switch (wrapper_fizzbuzz(argv[i])) {
			case FIZZ:
				argv[i] = f;
				break;
			case BUZZ:
				argv[i] = b;
				break;
			case FIZZBUZZ:
				argv[i] = fb;
				break;
			case PIZDEC:
				perror("Pizdec");
				break;
		}
		printf("%s\n", argv[i]);
	}
	return EXIT_SUCCESS;
}
