all : TP_Tortues

rebuild : clean all

TP_Tortues : main.o carte.o joueur.o plateau.o bot.o joueurReel.o tests_unitaires.o
	g++ -o TP_Tortues main.o carte.o joueur.o plateau.o bot.o joueurReel.o tests_unitaires.o

main.o : main.cpp 
	g++ -o main.o -c main.cpp

carte.o : carte.cpp
	g++ -o carte.o -c carte.cpp

joueur.o : joueur.cpp
	g++ -o joueur.o -c joueur.cpp

plateau.o : plateau.cpp
	g++ -o plateau.o -c plateau.cpp

bot.o : bot.cpp
	g++ -o bot.o -c bot.cpp

joueurReel.o : joueurReel.cpp
	g++ -o joueurReel.o -c joueurReel.cpp

tests_unitaires.o : tests_unitaires.cpp
	g++ -o tests_unitaires.o -c tests_unitaires.cpp

clean :
	del *.o
	rm *.o

#Pour ensuite executer : mingw32-make all puis .\TP_Tortues.exe