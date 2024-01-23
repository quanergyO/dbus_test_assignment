CXX = g++
FLAGS = -std=c++17 -Wall -Werror -Wextra
SANITIZE = -fsanitize=address
FILES = *.cpp

all: install

clean:
	rm -rf *.o *.out *.gch *.dSYM *.gcov *.gcda *.gcno *.a *.css *.html *.info test test_asan report html

install: clean
	mkdir build
	cd build && qmake ../viewCalc.pro && make

uninstall:
	rm -rf build

dvi:
	doxygen Doxyfile
	open html/index.html

dist:
	mkdir viewCalc/
	mkdir viewCalc/src
	cp Makefile *.cc headers/*.h viewCalc/src/
	tar cvzf SmartCalcService.tgz viewCalc/
	rm -rf viewCalc/
