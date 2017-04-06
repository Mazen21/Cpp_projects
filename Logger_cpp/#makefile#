all: loggy

clean:
	-rm main.o loggy.exe loggy

loggy: main.o
	g++ -g -o out/loggy main.o Logger.o

main.o: main.cpp
	g++ -c -g main.cpp src/Logger.cpp
