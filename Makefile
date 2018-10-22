main: dictionary.o main.o
	g++ dictionary.o main.o -o main

dictionary.o: dictionary.cpp
	g++ -Wall -c dictionary.cpp

main.o: main.cpp
	g++ -Wall -c main.cpp

clean:
	rm main.o main dictionary.o