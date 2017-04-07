main_objects = src/Logger.o main.o

all : main

main: $(main_objects)
	g++ -o out/loggy $(main_objects)

clean:
	find . -type f -name '*.o' -exec rm {} + 
