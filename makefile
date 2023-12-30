all: ./cpp/menu.cpp main.cpp ./cpp/agenda/agenda.cpp ./cpp/events.cpp ./cpp/save.cpp
	g++ -c ./cpp/menu.cpp main.cpp ./cpp/agenda/agenda.cpp ./cpp/events.cpp ./cpp/save.cpp
	g++ -o SAE1.exe menu.o main.o agenda.o events.o	save.o

clear : 
	rm -rf *.o
	rm -rf *.exe

clear_agendas :
	rm -rf agendas/*.agd