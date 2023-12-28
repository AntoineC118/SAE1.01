all: ./cpp/menu.cpp main.cpp ./cpp/agenda/agenda.cpp
	g++ -c ./cpp/menu.cpp main.cpp ./cpp/agenda/agenda.cpp
	g++ -o SAE1.exe menu.o main.o agenda.o

clear : 
	rm -rf *.o
	rm -rf *.exe