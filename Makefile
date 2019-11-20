#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o and student.o to executable main
main: main.o student.o domesticStudent.o internationalStudent.o toeflScore.o linkedListStudent.o
	g++ -g -lm -o main main.o student.o domesticStudent.o internationalStudent.o toeflScore.o linkedListStudent.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -g -c main.cpp

#compile the student.cpp to student.o
student.o: student.cpp
	g++ -g -c student.cpp

#compile the DomesticStudent.cpp to DomesticStudent.o
domesticStudent.o: domesticStudent.cpp
	g++ -g -c domesticStudent.cpp

#compile the InternationalStudent.cpp to InternationalStudent.o
internationalStudent.o: internationalStudent.cpp
	g++ -g -c internationalStudent.cpp

#compile the ToeflScore.cpp to ToeflScore.o
toeflScore.o: toeflScore.cpp
	g++ -g -c toeflScore.cpp
#compile the ToeflScore.cpp to ToeflScore.o
linkedListStudent: linkedListStudntent.cpp
	g++ -g -c linkedListStudent.cpp

#remove built files
clean:
	rm -rf main main.o student.o domesticStudent.o internationalStudent.o toeflScore.o linkedListStudent.o *~
