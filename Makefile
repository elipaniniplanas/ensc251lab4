#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o and student.o to executable main
main: main.o student.o Toefl.o
	g++ -std=c++11 -o main main.o student.o Toefl.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp

#compile the student.cpp to student.o
student.o: student.cpp
	g++ -std=c++11 -c student.cpp

#complie the Toefl.cpp to Toefl.o
Toefl.o: Toefl.cpp
	g++ -std=c++11 -c Toefl.cpp

#remove built files
clean:
	rm -rf main main.o student.o Toefl.o *~

