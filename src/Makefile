CC = g++
CFLAGS = -Wall -Werror -Wextra -Wshadow -std=c++17
HFILES = $(shell find . -type f | grep '\.h$$')
TPPFILES = $(shell find . -type f | grep '\.tpp$$')
CPPFILES = $(shell find . -type f | grep '\.cpp$$')
TESTS_FOLDER = tests
TMAIN = $(TESTS_FOLDER)/tests_main.cpp

SHELL = /bin/bash

TEXEC = $(TESTS_FOLDER).out
TFLAGS = -lgtest -lgtest_main
GFLAGS = --coverage

OS = $(shell uname)

RUN_EXEC = ./$(TEXEC) --gtest_brief=1

all: clang-format cppcheck gcov leaks

cppcheck:
	@cppcheck --enable=all --suppress=missingIncludeSystem --language=c++ --std=c++17 $(HFILES) $(CPPFILES) $(TPPFILES)

clang-format:
	@cp ../linters/clang-format .
	@clang-format -n --verbose --Werror $(HFILES) $(CPPFILES) $(TPPFILES)
	@rm clang-format

leaks: $(TEXEC)
ifeq ($(OS), Linux)
	valgrind --leak-check=full --show-leak-kinds=all -- $(RUN_EXEC)
endif
ifeq ($(OS), Darwin)
	leaks --atExit -- $(RUN_EXEC)
endif

test: build_tests
	@$(RUN_EXEC)

build_tests: clean $(TEXEC)

$(TEXEC): $(HFILES) $(TMAIN)
	@$(CC) $(CFLAGS) $(TMAIN) $(TFLAGS) -o $(TEXEC)

gcov: clean
	@$(CC) $(CFLAGS) $(TMAIN) $(TFLAGS) $(GFLAGS) -o $(TEXEC)
	@./$(TEXEC) > /dev/zero 2> /dev/zero
	@lcov -t report -c -d . -o report.info --no-external
	@genhtml report.info -o report
	@open ./report/index.html

clean:
	@rm -rf *.o *.gch *.out $(TEXEC) *.dSYM *.gcda *.gcno ./report *.info clang-format