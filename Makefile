SOURCES = fizzbuzz.c 
TEST = test.c
MAIN = main.c
OPTIONS = -std=c11 
all: build

build: $(SOURCES) $(MAIN)
	gcc $(OPTIONS) $(SOURCES) $(MAIN) -o fizzbuzz

test: $(SOURCES) $(TEST)
	gcc -fprofile-arcs -ftest-coverage $(OPTIONS) $(SOURCES) $(TEST) -o test

clean:
	-rm test fizzbuzz *.o *.d *.gcov *.gcno *.gcda
