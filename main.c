#include "fizzbuzz.h"

int main(int argc, char ** argv) {
	char f[] = "fizz";
	char b[] = "buzz";
	char fb[] = "fizzbuzz";
	for(int i = 1; i < argc; i++) {
		switch (fizzbuzz(argv[i])) {
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
