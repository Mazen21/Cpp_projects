all: loggy

clean:
	-rm main.o loggy.exe loggy

loggy: main.o
	g++ -g -o out/loggy main.o Bank.o

main.o: main.cpp
	g++ -c -g main.cpp src/Bank.cpp
