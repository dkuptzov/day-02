CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
GREP = main.c sprintf.c
QUEST1 = s21_grep

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

s21_sprintf: $(GREP)
	$(CC) $(CFLAGS) $^ -o $(QUEST1) -lm

.PHONY: clean

clean:
	rm -rf $(QUEST1) $(TARGET)

rebuild: clean $(TARGET)