bin/prog: build/main.o build/ship.o bin
	g++ build/main.o build/ship.o -o bin/prog -L/usr/local/lib/SFML -lsfml-graphics -lsfml-window -lsfml-system

build/main.o: src/main.cpp src/ship.hpp build
	g++ -c src/main.cpp -I/usr/local/include/SFML -o build/main.o

build/ship.o: src/ship.cpp src/ship.hpp build
	g++ -c src/ship.cpp -I/usr/local/include/SFML -o build/ship.o

build: 
	mkdir build

bin:
	mkdir bin

clean: 
	rm -rf bin build

.PHONY: all clean 
