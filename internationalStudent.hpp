#ifndef INTERNATIONALSTUDENT_HPP
#define INTERNATIONALSTUDENT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "student.hpp"
#include "toeflScore.hpp"

using namespace std;
//the class International student, a child of the class Student, contains two unique private member varibales,
//one for the country of which the student is from, and an object of class ToeflScore, so that the reading, 
//writing, speaking, listening, and total scores may be accessed.
class InternationalStudent : public Student
{
public:
	//constructor used to initialize the inputs, with FN = firstname, LN = last name, gradept = cgpa, research = research score, ID = application ID, homecountry = country
		//pre condition: pass values to use for initialzing international student object
		//post condition:initialized a international student object with these parameters
	InternationalStudent(string FN, string LN, float gradept, int research, int ID, string homecountry, int read, int listen, int speak, int write);

	//default constructor to initialize values when no parameters for initialization are passed
	//post condition: initialize international student objects to default values
	InternationalStudent();

	//pre condition: pass string to use to change country of the international student object
	//post condition: changed country of an international student
	void set_country(string home);

	//post condition:return the country of the international student object
	string get_country() const;

	//pre condition:pass reading score to change member of toefl score object
	//post condition: changed toefl reading score for the object
	void set_Tread(int read);

	//post condition: return toefl reading score
	int get_Tread() const;

	//pre condition: pass integer writing score to change for the international student object
	//post condition:changed the toefl writing score
	void set_Twrite(int write);

	//post condition:return toefl writing score
	int get_Twrite() const;

	//pre condition: pass integer listeining score to change it for the international student object
	//post condition:changed the toefl listening score
	void set_Tlisten(int listen);

	//post condition:return toefl listening score
	int get_Tlisten() const;

	//pre condition:pass the integer speaking score to change it for the international student object 
	//post condition:changed the toefl speaking score
	void set_Tspeak(int speak);

	//post condition:return the speaking score
	int get_Tspeak() const;

	//pre condition: pass integer values for individual scores to change total for the international student object
	//post condition:changed the toefl total score
	void set_Ttotal(int read, int write, int listen, int speak);

	//post condition:return the total toefl score
	int get_Ttotal() const;

	//pre condition:pass the 4 individual toefl scores, where total is represented by their sum, to check their validity
	//post condition:return true if they meet minimum requirements, false if not
	bool checkTOEFLreq(int read, int write, int speak, int listen);

	//pre condition: pass two international student objects to compare the alphabetic order of their country
	//post condition:return 1 if stu1's country preceeds stu2's alphabetically, return 0 if they are equal, and return -1 if stu2's preceeds
	friend int compareCountry(const InternationalStudent &stu1, const InternationalStudent &stu2);

	//pre condition: pass two international student objects to compare their total toefl scores
	//post condition: return 1 if stu1's is greater, 0 if theyre equal, and -1 if stu2's is greater
	friend int compareToeflScore(const InternationalStudent &stu1, const InternationalStudent &stu2);

	//pre condition: pass the output stream to write to and the international student object to print out
	//post condition: return the outpput stream with the information of stu written to it
	friend ostream& operator <<(ostream& outs, const InternationalStudent& stu);

	//pre condition:pass the object whose values are to be assinged to the other object
	//post condition:value of member variables of object on left side equal that of the left side
	void operator =(const InternationalStudent& right_side);

	//copy constructor
//pre condition:pass the object to be copied to another
//post condition:created identical copy of the international student object
	InternationalStudent(const InternationalStudent& Istu);
	friend bool operator == (InternationalStudent &student1, InternationalStudent &student2);

	//destructor
	//post condition: delete dynamic member varibale memory allocated for the international student object
	~InternationalStudent();

	//void insertNode(const InternationalStudent **internationalHeadNode,const InternationalStudent &Student1);

	//void insertSort(const InternationalStudent &Student1);


private:
	//private member varibales unique to InternationalStudent, where the TOEFL score is of type ToeflScore, so each InternationStudent class
	//has the ability to hold the individual scores of the Toefl, not just the total.
	string country;
	ToeflScore TOEFL;
};

#endif