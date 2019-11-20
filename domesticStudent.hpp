#ifndef DOMESTICSTUDENT_HPP
#define DOMESTICSTUDENT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "student.hpp"

using namespace std;
//the class DomesticStudent is for students that are from canada, with their specific province indicated.
//it is a child class of the class Student
class DomesticStudent : public Student
{
public:
	//constructor used to initialize the inputs, with FN = firstname, LN = last name, gradept = cgpa, research = research score, ID = application ID, prov = province
		//pre condition: pass values to use for initialzing domestic student object
		//post condition:initialized a domestic student object with these parameters
	DomesticStudent(string FN, string LN, float gradept, int research, int ID, string prov);

	//default constructor used when initializing values are not known
		//post condition:domestic student objedct intialized with default values
	DomesticStudent();

	//pre condition: pass string values to change province for a domestic student
	//post condition:changed the province member variable for a domestic student
	void set_province(string prov);

	//post condition:return the value of the province for the given student
	string get_province() const;

	//pre condition: pass two domestic student objects by reference to compare their provinces
	//post condition:return 1 if the province of stu1 preceeds stu2 in alphabet, 0 if they are equal, -1 if stu2's province preceeds stu1
	friend int compareProvince(const DomesticStudent &stu1, const DomesticStudent &stu2);

	//pre condition: pass the output stream for priting to, and a domestic student object whose information is to be printed
	//post condition:return the output stream containing info of stu to be printed
	friend ostream& operator <<(ostream& outs, const DomesticStudent& stu);

	//pre condition: pass an object whose member variables values are to be assinged to another object
	//post condition:object on the left of the equals sign holds the same values as the one on the right
	void operator =(const DomesticStudent& right_side);
	//allows comparison of domestic student objects
	friend bool operator ==(DomesticStudent &student1,DomesticStudent &student2);

	//copy constructor
	//pre condition: pass a domestic student object whose member variables are to be copied to another object
	//post condition:member varibales of Dstu copied to another object
	DomesticStudent(const DomesticStudent& Dstu);

	//delete dyanmic memory allocated for dynamic member variables
	~DomesticStudent();


private:
	//unique member variable to DomesticStudent
	string province;
};
#endif
