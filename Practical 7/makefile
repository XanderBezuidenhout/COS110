main: main.o bin.o train.o
	g++ main.o bin.o train.o -o main 

main.o: main.cpp
	g++ -g -c -std=c++98 main.cpp
	
bin.o: bin.cpp
	g++ -g -c -std=c++98 bin.cpp

train.o: train.cpp
	g++ -g -c -std=c++98 train.cpp
run: 
	./main

clean:
	rm *.o main

tar:
	tar -cvz main.cpp bin.cpp bin.h train.cpp train.h  makefile -f PRACTICAL7.tar
