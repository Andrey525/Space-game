bin/prog: build/main.o build/ship.o build/bullet.o build/danger.o bin
	g++ build/main.o build/ship.o build/bullet.o build/danger.o -o bin/prog -L/usr/local/lib/SFML -lsfml-graphics -lsfml-window -lsfml-system

build/main.o: src/main.cpp src/classes.hpp build
	g++ -c src/main.cpp -I/usr/local/include/SFML -o build/main.o

build/ship.o: src/ship.cpp src/classes.hpp build
	g++ -c src/ship.cpp -I/usr/local/include/SFML -o build/ship.o

build/bullet.o: src/bullet.cpp src/classes.hpp build
	g++ -c src/bullet.cpp -I/usr/local/include/SFML -o build/bullet.o

build/danger.o: src/danger.cpp src/classes.hpp build
	g++ -c src/danger.cpp -I/usr/local/include/SFML -o build/danger.o

build: 
	mkdir build

bin:
	mkdir bin

clean: 
	rm -rf bin build

.PHONY: all clean 
