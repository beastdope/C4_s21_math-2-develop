CC= gcc -Wall -Werror -Wextra -std=c11
MATH= ./functions/s21_*.c
OBJECTS= *.o
TEST= ./unit_tests/test_*.c ./unit_tests/test.c
CLANG= clang-format

.PHONY: all clean test rebuild

all: s21_math.a test gcov_report

s21_math.a:
	$(CC) $(CFLAGS) -c $(MATH)
	ar rcs s21_math.a $(OBJECTS)

test: s21_math.a
	$(CC) $(CFLAGS) $(MATH) $(TEST) s21_math.a -lcheck -o test
	./test

# build:
# 	$(CC) $(CFLAGS) s21_math.h *.c

clean:
	rm -rf *.o *.a test *.gch *.gcno *.gcda *.info report 

rebuild:
	make clean
	make all

# brew:
# 	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
# 	brew install lcov

gcov_report: s21_math.a
	$(CC) $(CFLAGS) --coverage $(MATH) $(TEST) -lcheck  -lm -o test 
	./test
	lcov -t "test" -o test_report.info -c -d .
	genhtml -o report test_report.info
	open report/index.html
	rm -rf *.o *.a  *.gch *.gcno test