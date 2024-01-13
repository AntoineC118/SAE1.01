all: ./src/menu.cpp main.cpp ./src/agenda.cpp ./src/events.cpp ./src/save.cpp
	g++ -I./include -Wall -std=c++17 -c src/*.cpp main.cpp
	g++ -o SAE1.exe *.o

clear : 
	rm -rf *.o
	rm -rf *.exe

clear_agendas :
	rm -rf agendas/*.agd