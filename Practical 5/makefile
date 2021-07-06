main.out: main.o vehicle.o locomotive.o dieselLocomotive.o electricLocomotive.o
	g++ main.o vehicle.o locomotive.o dieselLocomotive.o electricLocomotive.o -o main.out 

main.o: main.cpp
	g++ -g -c -std=c++98 main.cpp


vehicle.o: vehicle.cpp
	g++ -c -g -std=c++98 vehicle.cpp

locomotive.o: locomotive.cpp
	g++ -c -g -std=c++98 locomotive.cpp
	
dieselLocomotive.o: dieselLocomotive.cpp
	g++ -c -g -std=c++98 dieselLocomotive.cpp

electricLocomotive.o: electricLocomotive.cpp
	g++ -c -g -std=c++98 electricLocomotive.cpp
	
run: 
	./main.out

clean:
	rm *.o main.out

tar:
	tar -cvz main.cpp vehicle.h vehicle.cpp locomotive.h locomotive.cpp dieselLocomotive.h dieselLocomotive.cpp electricLocomotive.h electricLocomotive.cpp makefile -f PRACTICAL5.tar
