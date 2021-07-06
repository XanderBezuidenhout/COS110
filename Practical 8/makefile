main: main.o 
	g++ main.o -o main 

main.o: main.cpp LL.h LL.cpp item.h item.cpp
	g++ -g -c main.cpp
	
run: 
	./main

clean:
	rm *.o main

tar:
	tar -cvz *.h *.cpp *.pdf makefile -f PRACTICAL8.tar
