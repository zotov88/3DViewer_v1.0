FLAGS=-Werror -Wextra -Wall -std=c11 -g -lm
FLAGS_CHECK=$(shell pkg-config --cflags --libs check)
FLAGS_GCOV=-fprofile-arcs -ftest-coverage
DIR=backend

all: clean gcov_report install

clean:
	@rm -rf ./report ./latex ./html *.out $(DIR)/*.a $(DIR)/*.o $(DIR)/parcer *.info *.gcov *.gcda *.gcno *.tar *.a

install: create_dir_build
	@cd view/3DViewer && qmake6 && make && make clean && rm Makefile && cd ../../ && mv view/3DViewer/3DViewer build

uninstall:
	@rm -rf build

dvi:
	@doxygen dox/Doxyfile
	@open ./html/index.html

dist:
	@rm -rf dist.tar
	@tar -cvzf dist.tar build/3DViewer

test: clean
	@gcc $(CFLAGS) tests/test.c $(DIR)/*.c -o test.out $(FLAGS_CHECK)
	./test.out

gcov_report: clean
	@gcc $(FLAGS_GCOV) $(DIR)/*.c tests/test.c -o report.out $(FLAGS_CHECK)
	./report.out
	@lcov -t "report" -o report.info -c -d .
	@genhtml -o ./report report.info
	@open ./report/$(DIR)/index.html
	@rm -f *.gcov *.gcda *.gcno *.info report.out *.o

create_dir_build:
	@rm -rf build
	@mkdir build

check:
	checkmk tests/check.check > tests/test.c

valgrind:
	valgrind --leak-check=full --track-origins=yes ./parcer

git:
	git add .
	git commit -m "commit"
	git push

check_style:
	clang-format -style=Google -n $(DIR)/*.c $(DIR)/*.h tests/test.c

correct_style:
	clang-format -style=Google -i $(DIR)/*.c $(DIR)/*.h tests/test.c

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem $(DIR)/*.c $(DIR)/*.h tests/test.c

cpplint:
	python3 cpplint.py --extensions=c $(DIR)/*.c $(DIR)/*.h tests/test.c

all_check:
	make check_style
	make cppcheck
	make cpplint

parcer.o: parcer.c
	@gcc $(FLAGS) -c -o $(DIR)/parcer.o $(DIR)/parcer.c

transformation.o: transformation.c
	@gcc $(FLAGS) -c -o $(DIR)/transformation.o $(DIR)/transformation.c

app.a: $(DIR)/parcer.o $(DIR)/transformation.o
	@ar src $(DIR)/app.a $(DIR)/parcer.o $(DIR)/transformation.o
	@ranlib $(DIR)/app.a

