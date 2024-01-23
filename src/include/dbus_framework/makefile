CXX = g++
FLAGS = -std=c++17 -Wall -Werror -Wextra
SANITIZE = -fsanitize=address
FILES = *.cpp *.h applicationService/*.cpp applicationService/*.h

all: dist

clean:
	rm -rf *.o *.out *.gch *.dSYM *.gcov *.gcda *.gcno *.a *.css *.html *.info test test_asan report html

install: clean
	mkdir build
	cd build && qmake ../model.pro && make

uninstall:
	rm -rf build

dvi:
	doxygen Doxyfile
	open html/index.html

dist:
	mkdir dbus_framework/
	mkdir dbus_framework/src
	cp makefile ${FILES} dbus_framework/src/
	tar cvzf dbus_framework.tgz dbus_framework/
	rm -rf dbus_framework/
