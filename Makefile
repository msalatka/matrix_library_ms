# Kompilator i flagi
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g

# Nazwa programu
TARGET = main

# Pliki źródłowe
SRC = main.cpp

# Domyślny cel
all: $(TARGET)

# Kompilacja
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -Ilib $(SRC) -o $(TARGET)

# Czyszczenie plików binarnych
clean:
	rm -f $(TARGET)