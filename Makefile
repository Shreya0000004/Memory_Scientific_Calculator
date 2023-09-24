CC = g++
CFLAGS = -Wall -std=c++11
LDFLAGS =

TARGET = scientific_calculator_new

all: $(TARGET)

$(TARGET): main.o scientific_calculator_memory.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o scientific_calculator_memory.o $(LDFLAGS)

main.o: main.cpp scientific_calculator_memory.h
	$(CC) $(CFLAGS) -c main.cpp

scientific_calculator_memory.o: scientific_calculator_memory.cpp scientific_calculator_memory.h
	$(CC) $(CFLAGS) -c scientific_calculator_memory.cpp

clean:
	rm -f $(TARGET) *.o

