 # Copyright 2023 valeryje
 #
 # This file contains Original Code created by valeryje
 # aka Alexander Alexanyan or Alex-A-Nyan.
 #
 # The Original Code and all software developed in the process of
 # participation on learning by experimental programming educational method.
 # The whole methodology was developed and distributed by
 # Autonomous non-profit organization «School 21» (ANO «School 21»). 
 #
 # Redistribution and use of this file, its parts, or entire project
 # are permitted by confirmation of its original creator.


#  ====================================================================================================

# ----- SHORTCUTS -----  #
CC        = gcc
CFLAGS    = -Wall -Werror -Wextra -std=c11 -pedantic -g
TESTFLAGS = --coverage
FUNCTIONS = calc\
              review\
              algorithm\
              stack
LIBS      = -lcheck -lm -lgcov 

#  ====================================================================================================

# ----- TASK TARGETS ----- #
all: clean build uninstall install

clean:
	@-rm *.o
	@-rm test.c test.info *.gc*
	@-rm *.a
	@-rm test.out
	@-rm -rf report

build: objects
	ar rc main.a ./*.o
	@rm *.o

objects: lib.h
	for function in $(FUNCTIONS); do $(CC) $(CFLAGS) -c $$function.c -o $$function.o; done;

test: build 
	@checkmk clean_mode=1 test.check > test.c
	# clear
	@$(CC) test.c main.a $(LIBS) -o test.out
	@./test.out

install: 
	@-mkdir ~/SmartCalcV1.0_by_valeryje
	@-cp README_RUS.md ~/SmartCalcV1.0_by_valeryje/README_RUS.md
	@-cp QT/TheFlash.png ~/SmartCalcV1.0_by_valeryje/TheFlash.png
	@-cp QT/Reverse.jpeg ~/SmartCalcV1.0_by_valeryje/Reverse.jpeg
	@-cd QT && cmake -S . -B ~/SmartCalcV1.0_by_valeryje
	@-cd QT && cmake --build ~/SmartCalcV1.0_by_valeryje

uninstall:
	@-rm -rf ~/SmartCalcV1.0_by_valeryje
	
dvi: install
	@-open ~/SmartCalcV1.0_by_valeryje/README_RUS.md

dist: install
	@-tar -czf s21_smart_calc.tar ~/SmartCalcV1.0_by_valeryje

gcov_report: test
	@rm -rf report
	@for function in $(FUNCTIONS); do $(CC) -c $$function.c --coverage $(LIBS) -o $$function.o; done;
	@$(CC) *.o test.c $(TESTFLAGS) $(LIBS) -o test.out
	@-./test.out
	@lcov --directory . -c --output-file test.info
	@genhtml *.info -o report
	@-rm test.c test.info *.gc*
	@sleep 1
	@echo
	@echo OPENING COVERAGE REPORT
	@open report/index.html
	@sleep 1
	@clear

# ----- SUPPORT TARGETS ----- #
style:
	@cp ../materials/linters/.clang-format .clang-format
	@clear
	@clang-format -i *.c
	@clang-format -n *.c
	@rm .clang-format
	@sleep 0.2
	@echo Clang settings were applied
	@sleep 0.8
	@clear

run: install
	~/build_calculator/SmartCalc
