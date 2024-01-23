CXX = g++
FLAGS = -std=c++17 -Wall -Werror -Wextra
SANITIZE = -fsanitize=address
FILES = *.cpp
TARGETS = tests/test.cc
GCOV = -fprofile-arcs -ftest-coverage -fPIC -pthread
GTEST = -lgtest -lgtest_main -L/opt/homebrew/Cellar/googletest/1.14.0/lib

all: test

tests: clean
	${CXX} ${TARGETS} ${FLAGS} ${FILES} ${FLAGS} ${GCOV} ${GTEST} -o test -I/opt/homebrew/Cellar/googletest/1.14.0/include
	./test

gcov_report: tests
	mkdir report
	gcovr --html-details -o report/coverage.html
	open ./report/coverage.html

clean:
	rm -rf *.o *.out *.gch *.dSYM *.gcov *.gcda *.gcno *.a *.css *.html *.info test test_asan report html

install: clean
	mkdir build
	cd build && qmake ../creditCalcModel.pro && make

uninstall:
	rm -rf build

dvi:
	doxygen Doxyfile
	open html/index.html

dist:
	mkdir CreditCalcService/
	mkdir CreditCalcService/src
	cp makefile *.cpp *.h CreditCalcService/src/
	tar cvzf CreditCalcService.tgz CreditCalcService/
	rm -rf CreditCalcService/
