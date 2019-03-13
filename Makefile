SOURCES = fizzbuzz.c 
TEST = test.c
MAIN = main.c
OPTIONS = -std=c11 -pedantic
all: build

build: $(SOURCES) $(MAIN)
	gcc $(OPTIONS) $(SOURCES) $(MAIN) -o fizzbuzz

test: $(SOURCES) $(TEST)
	gcc $(OPTIONS) $(SOURCES) $(TEST) -o test

clean:
	-rm test fizzbuzz 
