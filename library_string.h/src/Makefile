FLAGS = -Wall -Werror -Wextra -std=c11
FUNC = s21_string.c
FUNC_LIB = s21_string.o
SRC = functions/*
OS := $(shell uname -s)
TEST_C = $(shell find tests -name "*.c")
LIB = s21_string.a

all: clean s21_string.a test gcov_report

s21_string:
	gcc $(FLAGS) $(SRC) -o s21_string

s21_string.o:
	gcc $(FLAGS) -c $(SRC)

s21_string.a: s21_string.o
	ar rc s21_string.a s21*.o
	ranlib s21_string.a



test: s21_string.a
ifeq ($(OS), Linux)
	gcc $(FLAGS) $(TEST_C) -o alltests $(LIB) -lcheck -lm -lpthread -lsubunit
	#  CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./alltests
else
	gcc $(FLAGS) $(TEST_C) -o alltests $(LIB) -lcheck -lpthread
endif
	./alltests


gcov_report: test
ifeq ($(OS), Linux)
	gcc $(FLAGS) -o alltests $(TEST_C) $(SRC) $(LIB) -lcheck -lm -lsubunit -lpthread --coverage
else
	gcc $(FLAGS) -o alltests $(TEST_C) $(SRC) $(LIB) -lcheck -lpthread --coverage
endif
	./alltests
	lcov -t "alltests" -o tests.info -c -d .
	genhtml -o report tests.info
	open report/index.html


clean:
	rm -rf main
	rm -rf out
	rm -rf s21_test
	rm -rf s21_string
	rm -rf alltests
	rm -rf *.o          
	rm -rf *.info
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.gcov
	rm -rf *.gch
	rm -rf *.out
	rm -rf *.a
	rm -rf *.dSYM
	rm -rf report

rebuild: clean all