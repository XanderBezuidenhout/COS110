main: main.o 
	g++ main.o -o main 

main.o: main.cpp dLL.h dLL.cpp cLL.h cLL.cpp storage.h storage.cpp
	g++ -g -c main.cpp
	
run: 
	./main

clean:
	rm *.o main

tar:
	tar -cvz *.h *.cpp *.pdf makefile -f PRACTICAL9.tar
