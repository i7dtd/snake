# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic
LDFLAGS = -lncurses

# Имена файлов
TARGET = program
SRC = src/test.c
OBJ = $(SRC:.c=.o)

# Основное правило по умолчанию (будет выполняться при просто 'make')
all: build

# Правило сборки (скомпилировать и слинковать)
build: $(TARGET)

# Создание исполняемого файла
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o bin/$(TARGET) $(OBJ) $(LDFLAGS)

# Компиляция .c файлов в .o файлы
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Запуск программы
run: build
	bin/$(TARGET)

# Отладка с gdb (опционально)
debug: CFLAGS += -g
debug: build
	gdb ./$(TARGET)

# Очистка скомпилированных файлов
clean:
	rm -f $(OBJ) $(TARGET)

# Указываем, что эти цели не являются файлами
.PHONY: all build run debug clean