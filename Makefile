CC = gcc -g

sum-input: sum-input.c
	$(CC) $^ sum-input-main.c -o $@

run-tests:
	$(CC) tests.c sum-input-main.c munit/munit.c -o test-suite

.PHONY: clean test
clean:
	rm sum-input

test: sum-input
	./test.sh

