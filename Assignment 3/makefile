main.out: main.o PalmVein.o ContactlessDevice.o FacialRecognition.o
	g++ main.o PalmVein.o ContactlessDevice.o FacialRecognition.o -o main 

main.o: main.cpp
	g++ -g -c -std=c++98 main.cpp
	
PalmVein.o: PalmVein.cpp
	g++ -c -g -std=c++98 PalmVein.cpp

ContactlessDevice.o: ContactlessDevice.cpp
	g++ -c -g -std=c++98 ContactlessDevice.cpp

FacialRecognition.o: FacialRecognition.cpp
	g++ -c -g -std=c++98 FacialRecognition.cpp
run: 
	./main

clean:
	rm *.o main

tar:
	tar -cvz Exception.h ContactlessDevice.cpp ContactlessDevice.h FacialRecognition.h FacialRecognition.cpp AccessDevice.h -f Task2.tar
