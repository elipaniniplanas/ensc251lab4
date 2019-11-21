#compile and link the application
all: main unitTest

#run the application
run: main
	./main

#this will execute the unit test program
test: unitTest
		./unitTest

#link main.o and student.o to executable main
main: main.o student.o
	g++ -g -o main main.o student.o

#link unitTest.o to executable test
unitTest: unitTest.o student.o
	g++ -g -c unitTest unitTest.o student.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -g -c main.cpp

#compile the student.cpp to student.o
student.o: student.cpp
	g++ -g -c student.cpp

#compile the unitTestMain.cpp to unitTest
#compile the unitTest.cpp to unitTest.o
unitTest.o: unitTest.cpp
	g++ -g -c unitTest.cpp

#remove built files
clean:
	rm -rf main main.o student.o unitTest.o *~
