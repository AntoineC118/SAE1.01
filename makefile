all: ./cpp/menu.cpp main.cpp ./cpp/agenda/agenda.cpp ./cpp/events.cpp
	g++ -c ./cpp/menu.cpp main.cpp ./cpp/agenda/agenda.cpp ./cpp/events.cpp
	g++ -o SAE1.exe menu.o main.o agenda.o events.o

clear : 
	rm -rf *.o
	rm -rf *.exe