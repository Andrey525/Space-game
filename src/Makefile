prog: main.o ship.o
	g++ main.o ship.o -o prog -L/usr/local/lib/SFML -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp ship.hpp
	g++ -c main.cpp -I/usr/local/include/SFML

ship.o: ship.cpp ship.hpp
	g++ -c ship.cpp -I/usr/local/include/SFML

clean:
	rm -rf prog main.o ship.o