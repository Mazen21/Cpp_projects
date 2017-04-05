all: loggy

clean:
	-rm main.o loggy.exe loggy

loggy: main.o
	g++ -g -o loggy main.o

main.o: main.cpp
	g++ -c -g main.cpp
