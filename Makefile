CC = g++
CFLAGS = -Wall -g

main: main.o car.o
	$(CC) $(CLAGS) -o main main.o car.o

main.o: main.cpp car.hpp
	$(CC) $(CFLAGS) -c main.cpp

car.o: car.hpp

clean:
	rm main
	rm car.o
	rm main.o