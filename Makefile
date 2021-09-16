bin/prog: build/main.o build/ship.o build/bullet.o build/danger.o bin
	g++ build/main.o build/ship.o build/bullet.o build/danger.o -o bin/prog -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

build/main.o: src/main.cpp src/classes.hpp build
	g++ -Wall -c src/main.cpp -o build/main.o

build/ship.o: src/ship.cpp src/classes.hpp build
	g++ -Wall -c src/ship.cpp -o build/ship.o

build/bullet.o: src/bullet.cpp src/classes.hpp build
	g++ -Wall -c src/bullet.cpp -o build/bullet.o

build/danger.o: src/danger.cpp src/classes.hpp build
	g++ -Wall -c src/danger.cpp -o build/danger.o

build: 
	mkdir build

bin:
	mkdir bin

clean: 
	rm -rf bin build

.PHONY: all clean 
