CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
GREP = main.c s21_atoi.c s21_binary.c s21_case.c s21_sprintf.c
OBJ = s21_atoi.o s21_binary.o s21_case.o s21_sprintf.o
TEST = check_tests
QUEST1 = s21_grep
QUEST2 = test
AR = ar
L = -lcheck -lsubunit -lm
LM = -lm
LIB_A = s21_string.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: s21_string.a test

s21_string.a: $(OBJ)
	$(AR) crs $@ $^
	rm -rf $(OBJ)

s21_sprintf: $(GREP)
	$(CC) $(CFLAGS) $^ -o $(QUEST1) $(LM)

test:
	$(CC) -o $(TEST) tests.c $(LIB_A) $(L)

.PHONY: clean

clean:
	rm -rf $(QUEST1) $(QUEST2) $(LIB_A) *.o

rebuild: clean all