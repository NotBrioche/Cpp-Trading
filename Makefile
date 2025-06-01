COMPILER = g++
CFLAGS = -Wall -g -std=c++17 -Iinclude
TARGET = main.exe

SRC = $(wildcard ./src/*.cpp)
OBJ = $(SRC:.cpp=.o)

all: clean $(TARGET)

$(TARGET): $(OBJ)
	$(COMPILER) $(CFLAGS) -o $(TARGET) $(OBJ)

src/%.o: src/%.cpp
	$(COMPILER) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	$(TARGET)

clean:
	rm -f $(TARGET) $(OBJ)