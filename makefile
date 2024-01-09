all: ./src/menu.cpp main.cpp ./src/agenda/agenda.cpp ./src/events.cpp ./src/save.cpp
	g++ -I./hpp -c ./src/menu.cpp main.cpp ./src/agenda/agenda.cpp ./src/events.cpp ./src/save.cpp
	g++ -o SAE1.exe menu.o main.o agenda.o events.o	save.o

clear : 
	rm -rf *.o
	rm -rf *.exe

clear_agendas :
	rm -rf agendas/*.agd