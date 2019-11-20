//Dakota Crozier and Colin Buchko
//ENSC 251 Assignment 
//
//student.cpp to define our classes, including member functions like an error check
//and constructors
#include "student.hpp" //header file where classes are declared
#include "domesticStudent.hpp"
#include "internationalStudent.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iomanip>

//STUDENT DEFINITION

//basic student constructor where FN is first name, LN is lastname, gradept is cgpa, and
//research and ID are researchscore and application ID values. Includes a call to the error
//check function for the cgpa, gradept, and research score parameters.
Student::Student(string FN, string LN, float gradept, int research, int ID)
{
	firstname = FN;
	lastname = LN;
	cgpa = gradept;
	researchscore = research;
	appID = ID;
	errorcheck();
}

//default student constructor that intializes the member variables to the specified values 
Student::Student()
{
	firstname = "NAME";
	lastname = "SURNAME";
	cgpa = 0.00;
	researchscore = 0;
	appID = 20200000;
	//extNode = NULL;
}

//student error checking function to make sure the cgpa is not less than 0 or greater than
//4.33, the research score is not less than 0 or more than 100, and the application id is 
//not more than 20210000 or less than 20200000
void Student::errorcheck()
{
	if ((cgpa < 0.00) || (cgpa > 4.33))
	{
		cout << "Error: Invalid CGPA. Exiting program";
		exit(1);
	}

	if ((researchscore < 0) || (researchscore > 100))
	{
		cout << "Error: Invalid Research Score. Exiting program";
		exit(1);
	}
	
	if ((appID < 20200000) || (appID > 20210000))
	{
		cout << "Errorcheck: Invalid Application ID. Exiting program";
		exit(1);
	}
}

//mutator/set function for the first name. Assume for lab1 that there are no issues
//in the string name provided
void Student::set_firstname(string name1)
{
	firstname = name1;
}

//accessor/get function for the first name variable
string Student::get_firstname() const
{
	return (firstname);
}

//mutator/set function for the last name. Assume for lab1 that there are no issues 
//with the string name provided
void Student::set_lastname(string name2)
{
	lastname = name2;
}

//accessor/get function for the last name variable
string Student::get_lastname() const
{
	return (lastname);
}
/*
//node accessor and mutator function
Student* Student::getnextNode() const{
	return (nextNode);
}
void Student::setnextNode(Student*node1) {
	this->nextNode = node1;
}
*/
//mutator/set function for the cgpa variable, where when wanting to set a new value
//for the cgpa, it is error checked each time to ensure the value is not less than 
//0.00 or more than 4.33 (4 point scale)
void Student::set_cgpa(float grade)
{
	cgpa = grade;
	
	if ((cgpa < 0.00) || (cgpa > 4.33))
	{
		cout << "Error: Invalid CGPA. Exiting program";
		exit(1);
	}
	
}

//accessor/get function to get the cgpa varibale
float Student::get_cgpa() const
{
	return (cgpa);
}

//mutator/set function for the research score variable, where the value RS, standing for
//research score, is assigned to researchscore (the private member var of student) and is 
//checked to be between 0 and 100, the min and max possible scores
void Student::set_researchscore(int RS)
{
	researchscore = RS;
	
	if ((researchscore < 0) || (researchscore > 100))
	{
		cout << "Error: Invalid Research Score. Exiting program";
		exit(1);
	}
	
}

//accessor/get function for the researchscore variable
int Student::get_researchscore() const
{
	return (researchscore);
}

//mutator/set function for the application ID number, where the value passed
//is checked to be between 20200000(first student) and 20210000 (10000th student)
void Student::set_appID(int IDnum)
{
	appID = IDnum;
	
	if ((appID < 20200000) || (appID > 20210000))
	{
		cout << "Error: Invalid Application ID. Exiting program";
		exit(1);
	}
	
}

//accessor/get function for the application id variable
int Student::get_appID() const
{
	return (appID);
}

//compare cgpa of two students, by returning 1 if the first obj has a greater value, 0 if equal, and -1 of second obj is greater
int compareCGPA(Student stu1, Student stu2)
{
	if (stu1.get_cgpa() > stu2.get_cgpa())
	{
		return(1);//1 is first obj parameter is greater
	}
	if (stu1.get_cgpa() == stu2.get_cgpa())
	{
		return(0);//0 if equal
	}
	if (stu1.get_cgpa() < stu2.get_cgpa())
	{
		return(-1);//-1 if second obj parameter is greater
	}
}

//compare research score of two students, returning 1 if first obj parameter is greater, 0 if equal, -1 if second is greater
int compareResearchScore(Student stu1, Student stu2)
{
	if (stu1.get_researchscore() > stu2.get_researchscore())
	{
		return(1);//1 if first obj parameter is greater
	}
	if (stu1.get_researchscore() == stu2.get_researchscore())
	{
		return(0);//0 if theyr equal
	}
	if (stu1.get_researchscore() < stu2.get_researchscore())
	{
		return(-1);//-1 if second obj parameter is greater
	}
}

//compare firstnames of two objects by going thru while loop examining each character. If tbey are the same but one is shoter length, ie Zoe vs Zoey, the one with less letters preceeds
//Z has a larger ASCII value than A, so if its greater then it means the lesser value one preceeds
int compareFirstName(Student stu1, Student stu2)
{
	int i = 0;
	while (stu1.get_firstname()[i] != '\0' && stu2.get_firstname()[i] != '\0')
	{
		if (stu1.get_firstname()[i] < stu2.get_firstname()[i])
		{
			return(1);//return 1 if the stu1 object preceeds alphabetically, meaning it has a lesser string value
		}
		if (stu1.get_firstname()[i] > stu2.get_firstname()[i])
		{
			return(-1); //return -1 if stu2 preceeds alphabetically (lower ASCII)
		}
		i++;//increment while loop
	}
	//check for if the strings are have same first few letters but one has ended and other did not. Shorter length one preceeds
	if (stu1.get_firstname()[i] == '\0' && stu2.get_firstname()[i] != '\0')
	{
		return(1);
	}
	if (stu1.get_firstname()[i] != '\0' && stu2.get_firstname()[i] == '\0')
	{
		return(-1);
	}

	return(0);
}

//comapare last names in same manner as first name. Lower ASCII value character preceeds alphabetically, check with loop counter for each character
int compareLastName(Student stu1, Student stu2)
{
	int i = 0;
	while (stu1.get_lastname()[i] != '\0' && stu2.get_lastname()[i] != '\0')
	{
		if (stu1.get_lastname()[i] < stu2.get_lastname()[i])
		{
			return(1);//return 1 if stu1 preceeds alphabetically
		}
		if (stu1.get_lastname()[i] > stu2.get_lastname()[i])
		{
			return(-1);//return -1 if stu2 preceeds alphabetically
		}
		i++;
	}
	//check if the last names are identicaly except one is shorter length. Shorter length one preceeds alphabetically
	if (stu1.get_lastname()[i] == '\0' && stu2.get_lastname()[i] != '\0')
	{
		return(1);
	}
	if (stu1.get_lastname()[i] != '\0' && stu2.get_lastname()[i] == '\0')
	{
		return(-1);
	}
	return(0);
}



