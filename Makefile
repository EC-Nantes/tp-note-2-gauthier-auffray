all : TP_Tortues

rebuild : clean all

TP_Tortues : main.o point2D.o 
	g++ -o TP_Tortues main.o point2D.o 

main.o : main.cpp 
	g++ -o main.o -c main.cpp

point2D.o : point2D.cpp
	g++ -o point2D.o -c point2D.cpp


clean :
	del *.o

#Pour ensuite executer : mingw32-make all puis .\TP_Tortues.exe