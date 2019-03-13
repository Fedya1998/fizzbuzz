SOURCES = fizzbuzz.c 
TEST = test.c
MAIN = main.c

all: build

build: $(SOURCES) $(MAIN)
	gcc $(SOURCES) $(MAIN) -o fizzbuzz

test: $(SOURCES) $(TEST)
	gcc $(SOURCES) $(TEST) -o test

clean:
	-rm test fizzbuzz 
