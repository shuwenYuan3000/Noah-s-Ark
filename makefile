noah.o: noah.cpp judge.h
	g++ -c noah.cpp

noah: noah.o
	g++ noah.o -o noah
