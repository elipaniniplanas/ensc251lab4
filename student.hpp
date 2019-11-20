
//Dakota and Colin
//ENSC 251 Lab Assingment 
//
//header file student.hpp to declare the class ToeflScore, the class Student, and child classes of 
//student called DomesticStudent and InternationalStudent.
//DomesicStudent contains the unique member variable 'province', and InternationalStudent contains
//the unique member varibles 'country' and 'TOEFL'. The other variables, like first and last name,
//student number, researchscore, etc are inherited from parent class Student. 

#ifndef STUDENT_H //to avoid multiple class definitions
#define STUDENT_H
#include <iostream>
#include <string>
#include <cstdlib>
//#include <fstream>
//#include <sstream>

using namespace std;

//the class Student contains the basic elements/info obtained for generic students, including things like
//the first and last names, and cgpa. These are general to all students, and is therefore used for both
//international and domestic studets (hence why its the parent class)
class Student
{
public:
	//constructor used to initialize basic elements of a student, with FN = first name, LN = last name, gradept = cgpa, research = research score, id = application id
	//pre condition: pass 5 parameters to describe a student, with first name, last name, cgpa, research score and application ID
	//post condition: assigns the parameters to their corresponding private member variable
	Student(string FN, string LN, float gradept, int research, int ID);


	//default student constructor
	//post condition: initializes values to default ones
	Student();

	//pre condition: pass string input parameter to use for assiging the first name of a student
	//post condition: assigns the passed name to private member variable first name
	void set_firstname(string name1);

	//post condition:return the first name of the student
	string get_firstname() const;

	//pre condition: pass a string parameter for changing the last name of the student
	//post condition: assign the parameter to the last name varibale for the student
	void set_lastname(string name2);

	//post condition: return the first name of the student
	string get_lastname() const;

	//pre condition: pass a float value for the cgpa of the student
	//post condition:changed the value of the cgpa of the student
	void set_cgpa(float grade);

	//post condition: return the value of the cgpa of the student
	float get_cgpa() const;

	//pre condition: pass an integer value for the research score of the student, to use as the new score
	//post condition:changed the value of the research score of the student
	void set_researchscore(int RS);

	//post condition: return the research score of the student
	int get_researchscore() const;

	//pre condition: pass the integer value of the student id number for changing the current one
	//post condition: changed the value of the student id number
	void set_appID(int IDnum);

	//post condition:return the value of the application id/student number of the student
	int get_appID() const;

	//pre condition:pass 2 student objects(or children of student) for comparing their cgpa's
	//post condition:return 1 if stu1 has a greater cgpa, 0 if theyre equal, -1 if stu2 has a greater cgpa
	friend int compareCGPA(Student stu1, Student stu2);

	//pre condition: pass 2 student/student children objects to compare their research scores
	//post condition:return 1 if stu1 has a greater RS, 0 if theyre equal, -1 if stu2 has a greater RS
	friend int compareResearchScore(Student stu1, Student stu2);

	//pre condition: pass 2 student/student children objects to compare their first names
	//post condition:return 1 if stu1 preceeds in alphabet, 0 if theyre the same, and -1 if stu2 preceeds
	friend int compareFirstName(Student stu1, Student stu2);

	//pre condition: pass 2 student/student children objects to compare their last names
	//post condition:return 1 if stu1 preceeds in alphabet, 0 if theyre the same, and -1 if stu2 preceeds
	friend int compareLastName(Student stu1, Student stu2);

	//post condition: checks cgpa, research score, and application ID for validity. If either fails, exit the program
	void errorcheck();

	//Student* getnextNode() const;
	//void setnextNode(Student*node);
	


private:
	//private member variables, where appID is the assigned application ID of the student
	string firstname;
	string lastname;
	float cgpa;
	int researchscore;
	int appID;
	//pointer to next node
	//Student *nextNode;
};





#endif //STUDENT_H
