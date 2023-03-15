all : TP_Tortues

rebuild : clean all

TP_Tortues : main.o carte.o joueur.o plateau.o
	g++ -o TP_Tortues main.o carte.o joueur.o plateau.o

main.o : main.cpp 
	g++ -o main.o -c main.cpp

carte.o : carte.cpp
	g++ -o carte.o -c carte.cpp

joueur.o : joueur.cpp
	g++ -o joueur.o -c joueur.cpp

plateau.o : plateau.cpp
 	g++ -o plateau.o -c plateau.cpp

clean :
	del *.o

#Pour ensuite executer : mingw32-make all puis .\TP_Tortues.exe