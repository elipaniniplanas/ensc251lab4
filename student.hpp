#ifndef STUDENT_HPP
#define STUDENT_HPP


//header file student.hpp to declare your classes
using namespace std; //use namespace std
#include <string> //you will have to use string in C++

class ToeflScore
{
public:
	ToeflScore();
	ToeflScore(int reads, int listen, int speak, int writes);
	void setToefl(int reads, int listen, int speak, int writes);
	int get_reading()const;
	int get_listening()const;
	int get_speaking()const;
	int get_writing()const;
	int get_total()const;
private:
	int reading;
	int listening;
	int speaking;
	int writing;
	int total;
};

class Student
{

	typedef Student* studentPtr;

protected:


	virtual void print(ostream& where) const;

public:

	friend void merge( studentPtr domlist,  studentPtr intlist, studentPtr &Head, studentPtr &Tail);

	Student();	// default student constructor
	Student(string first, string last, float cgpaSc, int researchSc, int idNum); // constructor for student with all parameters
	void setStudent(string first, string last, float cgpaSc, int researchSc, int idNum); // set function for student to change values values of private members


	friend studentPtr search(studentPtr &head, studentPtr &newnode, char& choice);

	friend void insert(studentPtr stu, studentPtr &head, studentPtr &tail, studentPtr& newnode, const char& choice);


	string get_firstname() const;
	string get_lastname()const;
	float get_cgpa()const;
	int get_reScore()const;
	int get_id()const;

	virtual void set_link(studentPtr link);
	virtual studentPtr get_link() const;

	// most of our friend functions are now in the student class, since we use a Student* and need access// however, we can still change dynamically allocated domestic and international students becuase of our virtual location
	friend int compareCGPA(Student* stu1, Student* stu2);
	friend int compareResearchScore(Student* stu1, Student* stu2);
	friend int compareFirstName(Student *stu1, Student *stu2);
	friend int compareLastName(Student *stu1, Student *stu2);
	friend int compareLocation(const studentPtr& stu1, const studentPtr& stu2);

	friend void threshold(studentPtr head, float cgpa, int research);

	virtual void set_location(string prov);
	virtual string get_location() const;

	friend void searchID(studentPtr head1, studentPtr head2, int num);
	friend void searchCGPA(studentPtr head1, studentPtr head2, float num);
	friend void searchReScore(studentPtr head1, studentPtr head2, int num);
	friend void searchName(studentPtr head1, studentPtr head2, string first, string last);

	friend studentPtr deleteSearch(studentPtr head, studentPtr temphead, char& choice, string first, string last);
	friend void deleteStudent(studentPtr &head, studentPtr &tail, studentPtr &beforeDelete, char& choice);


	friend ostream& operator <<(ostream& out, Student& domstu);

	~Student();

private:
	string firstname;
	string lastname;
	float cgpa;
	int reScore; // Research Score
	int id;
	studentPtr link;
	string location;

};

/*
	DomesticStudent and InternationalStudent are child classes of Student which means that they would have acces to the functions and private
	members of the Student class. The child class can also introduce new functions and private members, specific to the new child class
*/

class DomesticStudent : public Student // Child of Student
{
public:
	typedef DomesticStudent* domesticStudentPtr;
	typedef Student* studentPtr;


	DomesticStudent(); // default constructor for domestic student
	DomesticStudent(string first, string last, float cgpaSc, int researchSc, int idNum, string prov); // constructor with all parameters for domestic student
	DomesticStudent(const DomesticStudent& domestic); // copy constructor

	virtual void set_location(string prov); // set functions to change value of province private member
	virtual string get_location() const;

	virtual void print(ostream& out) const;
	friend ostream& operator <<(ostream& out, DomesticStudent& domstu);

	void operator =(const DomesticStudent& right_side);

	//friend studentPtr searchDom(studentPtr &head, studentPtr &newdom, char& choice);
	//friend void insertDom(studentPtr temp, studentPtr &head, studentPtr &tail, const char& choice, string first, string last, float cgpaSc, int researchSc, int idNum, string prov);


	~DomesticStudent();

private:
	string province;

};

class InternationalStudent : public Student
{
public:

	typedef InternationalStudent* internationalStudentPtr;
	typedef Student* studentPtr;

	InternationalStudent(); // default constructor for international student
	InternationalStudent(string first, string last, float cgpaSc, int researchSc, int idNum, string countryName, int reads, int listen, int speak, int writes);
	InternationalStudent(const InternationalStudent&);

	void setInternationalScores(int reads, int listen, int speak, int writes); // set function for Toefl scores




	virtual void print(ostream& where) const;
	friend ostream& operator <<(ostream& out, InternationalStudent& intstu);
	void operator =(const  InternationalStudent& right_side);

	virtual void set_location(string prov); // set functions to change value of province private member
	virtual string get_location() const;


	// simple get function to use values from private members
	int get_read() const;
	int get_write() const;
	int get_listen() const;
	int get_speak()const;
	int get_totals()const;
	~InternationalStudent();

private:
	string country;
	ToeflScore scores;

};

#endif
