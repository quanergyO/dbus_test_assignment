CXX = g++
FLAGS = -std=c++17 -Wall -Werror -Wextra
SANITIZE = -fsanitize=address
FILES = *.cc
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
	rm -rf *.o *.out *.gch *.dSYM *.gcov *.gcda *.gcno *.a *.css *.html *.info test test_asan report
.PHONY: tests clean gcov_report style

install: clean
	mkdir build
	cd build && qmake ../model.pro && make

uninstall:
	rm -rf build

dvi:
	doxygen Doxyfile
	open html/index.html

dist:
	mkdir SmartCalcService/
	mkdir SmartCalcService/src
	cp Makefile *.cc headers/*.h SmartCalcService/src/
	tar cvzf SmartCalcService.tgz SmartCalcService/
	rm -rf SmartCalcService/
