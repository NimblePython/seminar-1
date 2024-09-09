# Определение компилятора и флагов
CC = g++
CFLAGS = -Wall -std=c++11 -Iinclude

# Определение исполняемого файла
TARGET = program

# Список исходных файлов и объектных файлов
SRCS = main.cpp utils.cpp data.cpp
OBJS = $(SRCS:.cpp=.o)

# Правило по умолчанию
all: $(TARGET)

# Правило для создания исполняемого файла
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Правило для компиляции .cpp файлов в .o файлы
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Правило для удаления всех сгенерированных файлов
clean:
	rm -f $(OBJS) $(TARGET)

# Объявление целей, которые не являются файлами
.PHONY: all clean
