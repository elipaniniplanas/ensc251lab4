//student.cpp to implement your classes
#include "student.hpp"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

typedef Student* studentPtr;
typedef DomesticStudent* domesticStudentPtr;
typedef InternationalStudent* internationalStudentPtr;

ToeflScore::ToeflScore() // default constructor assigns all values to 0
{
	reading = 0;
	listening = 0;
	speaking = 0;
	writing = 0;
}

ToeflScore::ToeflScore(int reads, int listen, int speak, int writes) // sets all the values from the toefl score
{
	reading = reads;
	listening = listen;
	speaking = speak;
	writing = writes;

}

void ToeflScore::setToefl(int reads, int listen, int speak, int writes)
{

	// all the Toefl scores have to be between the range of 0 to 30
	// this is just a simple error check for all the values

	if (reads <= 30 && reads >= 0)
	{
		reading = reads;
	}
	else
	{
		cerr << "Reading Score is not Valid.\n Exiting program.\n";
		exit(0);
	}

	if (listen <= 30 && listen >= 0) {
		listening = listen;
	}
	else
	{
		cerr << "Listening Score is not Valid.\n Exiting program.\n";
		exit(1);
	}

	if (speak <= 30 && speak >= 0) {
		speaking = speak;
	}
	else {
		cerr << "Speaking Score is not Valid.\n Exiting program.\n";
		exit(2);
	}

	if (writes <= 30 && writes >= 0) {
		writing = writes;
	}
	else {
		cerr << "Listening Score is not Valid.\n Exiting program.\n";
		exit(3);
	}


	total = reads + listen + speak + writes;

}

// Get functions for the class Toeflscore

int ToeflScore::get_reading()const
{
	return reading;
}
int ToeflScore::get_listening()const
{
	return listening;
}
int ToeflScore::get_speaking()const
{
	return speaking;
}
int ToeflScore::get_writing()const
{
	return writing;
}
int ToeflScore::get_total()const
{
	return total;
}

Student::Student() { // sets all values for the student class to zero


	firstname = "";
	lastname = "";
	cgpa = 0;
	reScore = 0;
	id = 0;
	link = nullptr;

}
Student::Student(string first, string last, float cgpaSc, int researchSc, int idNum)
{
	setStudent(first, last, cgpaSc, researchSc, idNum);
	link = nullptr;
}


void Student::print(ostream& where) const
{
}

// Student destructor
Student::~Student() {


}

DomesticStudent::DomesticStudent()
{
	province = "";
}
DomesticStudent::DomesticStudent(string first, string last, float cgpaSc, int researchSc, int idNum, string prov)
{
	setStudent(first, last, cgpaSc, researchSc, idNum);
	set_location(prov);

}
DomesticStudent::DomesticStudent(const DomesticStudent& domestic) { //Domestic copy constructor

	DomesticStudent stu;

	stu.set_location(domestic.get_location());
	stu.setStudent(domestic.get_firstname(), domestic.get_lastname(), domestic.get_cgpa(), domestic.get_reScore(), domestic.get_id());

};

// DomesticStudent destructor
DomesticStudent::~DomesticStudent() {


}
InternationalStudent::InternationalStudent() {

	country = "";
	scores.setToefl(0, 0, 0, 0);

}
InternationalStudent::InternationalStudent(string first, string last, float cgpaSc, int researchSc, int idNum, string countryName, int reads, int listen, int speak, int writes)
{
	setStudent(first, last, cgpaSc, researchSc, idNum);
	set_location(countryName);
	setInternationalScores(reads, listen, speak, writes);

}
InternationalStudent::InternationalStudent(const InternationalStudent& international) { // International copy constructor

	InternationalStudent stu;

	stu.set_location(international.get_location());
	stu.setInternationalScores(international.get_read(), international.get_listen(), international.get_speak(), international.get_write());
	stu.setStudent(international.get_firstname(), international.get_lastname(), international.get_cgpa(), international.get_reScore(), international.get_id());

};


// InternationalStudent destructor
InternationalStudent::~InternationalStudent() {

}


//////////////////////  Friend Compare Functions //////////////////////

int compareCGPA(Student *stu1, Student *stu2)
{	// return  1 - stu1 > stu2
	// return  2 - stu1 < stu2
	// return  3 - stu1 == stu2

	if (stu1->get_cgpa() > stu2->get_cgpa())
	{
		return 1;
	}
	else if (stu1->get_cgpa() < stu2->get_cgpa())
	{
		return 2;
	}
	else
	{
		return 3;
	}
}

int compareResearchScore(Student* stu1, Student* stu2)
{
	// return  1 - stu1 > stu2
	// return  2 - stu1 < stu2
	// return  3 - stu1 == stu2
	if (stu1->get_reScore() > stu2->get_reScore())
	{
		return 1;
	}
	else if (stu1->get_reScore() < stu2->get_reScore())
	{
		return 2;
	}
	else
	{
		return 3;
	}
}

int compareFirstName(Student *stu1, Student *stu2)
{
	// return  1 - stu1 goes before stu2
	// return  2 - stu1 goes after stu2
	// return  3 - stu1 and stu2 are equal
	string fname1 = stu1->get_firstname();
	transform(fname1.begin(), fname1.end(), fname1.begin(), ::tolower);
	string fname2 = stu2->get_firstname();
	transform(fname2.begin(), fname2.end(), fname2.begin(), ::tolower);

	int i = 0;
	while (fname1[i] != '\0' && fname2[i] != '\0') // This loop is to check the end of the string (name)
	{
		if (fname1[i] > fname2[i])  // We are following the ASCI characters. The letter Z is a bigger number than the letter A
		{
			return 2;
		}
		else if (fname1[i] < fname2[i])
		{
			return 1;
		}
		else
		{
			i++;
			continue;
		}

	}

	if (fname1[i] == fname2[i])
	{
		return 3;
	}
	else if (fname1[i] == '\0') // if stu1's name is shorter and all the other characters are the same as the other, it goes first
	{
		return 1;
	}
	else
	{
		return 2;
	}
}


int compareLastName(Student *stu1, Student *stu2)
{
	// return  1 - stu1 goes before stu2
	// return  2 - stu1 goes after stu2
	// return  3 - stu1 and stu2 are equal
	string lname1 = stu1->get_lastname();
	transform(lname1.begin(), lname1.end(), lname1.begin(), ::tolower);
	string lname2 = stu2->get_lastname();
	transform(lname2.begin(), lname2.end(), lname2.begin(), ::tolower);
	int i = 0;
	while (lname1[i] != '\0' && lname2[i] != '\0')
	{
		if (lname1[i] > lname2[i])
		{
			return 2;
		}
		else if (lname1[i] < lname2[i])
		{
			return 1;
		}
		else
		{
			i++;
			continue;
		}

	}

	if (lname1[i] == lname2[i])
	{
		return 3;
	}
	else if (lname1[i] == '\0')
	{
		return 1;
	}
	else
	{
		return 2;
	}
}
int compareLocation(const studentPtr& stu1, const studentPtr& stu2) // we have reworked the compare function so that we no longer need 2 seperate functions for domestic and international
{
	// return  1 - stu1 goes before stu2
	// return  2 - stu1 goes after stu2
	// return  3 - stu1 and stu2 are equal
	int i = 0;

	while (stu1->get_location()[i] != '\0' && stu2->get_location()[i] != '\0') // depending on the type of object the pointers point to, the get_location will get either province or country!!
	{
		if (stu1->get_location()[i] > stu2->get_location()[i])
		{
			return 2;
		}
		else if (stu1->get_location()[i] < stu2->get_location()[i])
		{
			return 1;
		}
		else
		{
			i++;
			continue;
		}

	}

	if (stu1->get_location()[i] == stu2->get_location()[i])
	{
		return 3;
	}
	else if (stu1->get_location()[i] == '\0')
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

/////////////////////////////////////////////////////////////////////////

void Student::setStudent(string first, string last, float cgpaSc, int researchSc, int idNum)
{
	firstname = first;
	lastname = last;

	if (cgpaSc <= 4.33 && cgpaSc >= 0)
	{
		cgpa = cgpaSc;
	}
	else {
		cerr << "Error: not a valid cgpa \n " << "closing the program. \n";
		exit(10); // If there are any errors with the text file, the program closes
	}

	if (researchSc <= 100 && researchSc >= 0)
	{
		reScore = researchSc;
	}
	else {
		cerr << "Error: not a valid Research Score \n " << "closing the program. \n";
		exit(11);
	}

	if (idNum <= 20210000 && idNum >= 20200000) { // The max ID num is 20210000

		id = idNum;
	}
	else {
		cerr << "Error: not a valid ID \n " << "closing the program. \n";
		exit(12);
	}
}

// These are the get and set functions for our links
studentPtr Student::get_link()const {
	return link;
}
void Student::set_link(studentPtr lnk) {
	link = lnk;
}


string Student::get_firstname() const
{
	return firstname;
}
string Student::get_lastname()const
{
	return lastname;
}
float Student::get_cgpa()const
{
	return cgpa;
}
int Student::get_reScore()const
{
	return reScore;
}
int Student::get_id()const
{
	return id;
}

void DomesticStudent::set_location(string prov) // the DomesticStudent virtual function of location. This function makes sure the user inputs a correct province and stores it in the province private member
{
	if (prov == "BC" || prov == "AB" || prov == "ON" || prov == "MB" || prov == "NB" || prov == "NL" || prov == "YT" || prov == "SK" || prov == "NU" || prov == "NS" || prov == "QC" || prov == "NT" || prov == "NU" || prov == "PE")
	{
		province = prov;
	}
	else {
		cerr << "Error: not a valid province \n " << "closing the program. \n";
		exit(13);
	}
}

// virtual function for outputing name
void DomesticStudent::print(ostream& out) const
{


	cout << setw(15) << left << get_firstname()
		<< setw(15) << left << get_lastname()
		<< setw(15) << left << province
		<< setw(10) << left << get_cgpa()
		<< setw(18) << left << get_reScore()
		<< setw(15) << left << get_id()  << endl;

}

string DomesticStudent::get_location() const // virtual get_location returns province instead of location private member
{
	return province;
}

ostream& operator <<(ostream& out, Student& stu) {
	stu.print(out);
	return out;
}


// Overload for the Domestic '<<' operator
ostream& operator <<(ostream& out, DomesticStudent& domstu)
{
	out << setw(15) << left << domstu.get_firstname()
		<< setw(15) << left << domstu.get_lastname()
		<< setw(15) << left << domstu.province
		<< setw(10) << left << domstu.get_cgpa()
		<< setw(18) << left << domstu.get_reScore()
		<< setw(15) << left << domstu.get_id()  << endl;
	return out;
}


void InternationalStudent::setInternationalScores(int reads, int listen, int speak, int writes)
{
	scores.setToefl(reads, listen, speak, writes); // scores is an object of the ToeflScore class
}


int InternationalStudent::get_read()const
{
	return scores.get_reading();
}
int InternationalStudent::get_write()const
{
	return scores.get_writing();
}
int InternationalStudent::get_listen()const
{
	return scores.get_listening();
}
int InternationalStudent::get_speak()const
{
	return scores.get_speaking();
}
int InternationalStudent::get_totals()const
{
	return scores.get_total();
}

// Overload for the International '<<' operator
ostream& operator <<(ostream& out, InternationalStudent& intstu)
{

	out << setw(15) << left << intstu.get_firstname()
		<< setw(15) << left << intstu.get_lastname()
		<< setw(15) << left << intstu.get_location()
		<< setw(10) << left << intstu.get_cgpa()
		<< setw(18) << left << intstu.get_reScore()
		<< setw(15) << left << intstu.get_id()
		<< setw(10) << left << intstu.get_totals()
		<< setw(10) << left << intstu.get_read()
		<< setw(10) << left << intstu.get_listen()
		<< setw(10) << left << intstu.get_speak()
		<< setw(10) << left << intstu.get_write()  << endl;

	return out;
}

//virtual print function for international student
void InternationalStudent::print(ostream& where) const
{

	cout << setw(15) << left << get_firstname()
		<< setw(15) << left << get_lastname()
		<< setw(15) << left << get_location()
		<< setw(10) << left << get_cgpa()
		<< setw(18) << left << get_reScore()
		<< setw(18) << left << get_id()
		<< setw(10) << left << get_totals()
		<< setw(10) << left << get_read()
		<< setw(10) << left << get_listen()
		<< setw(10) << left << get_speak()
		<< setw(10) << left << get_write()  << endl;
}

// Overload for the International assignment operator
void InternationalStudent::operator =(const InternationalStudent& right_side) {

	set_location(right_side.get_location());
	setInternationalScores(right_side.get_read(), right_side.get_listen(), right_side.get_speak(), right_side.get_write());
	setStudent(right_side.get_firstname(), right_side.get_lastname(), right_side.get_cgpa(), right_side.get_reScore(), right_side.get_id());


}




// Overload for the International assignment operator
void DomesticStudent::operator =(const DomesticStudent& right_side) {


	set_location(right_side.get_location());
	setStudent(right_side.get_firstname(), right_side.get_lastname(), right_side.get_cgpa(), right_side.get_reScore(), right_side.get_id());
	set_link(right_side.get_link());

}

studentPtr search(studentPtr &head, studentPtr &newnode, char& choice) // Function shows where the new node should be inserted, based on the overal sort
{
	// choice is a character variable that the user sends in, this tells us which type of insert we need
	studentPtr temp;
	studentPtr temp2 = nullptr;

	temp = head;

	if (temp != nullptr) { // First check if the list is empty or only has one node
		temp2 = temp->get_link(); // Our implementation always has 2 pointers - one(temp2) for testing to see where to sort and one to send to the insert(temp)
	}
	else {
		choice = 'B'; // if empty, we need to set both the head and tail to a new node
		return temp;
	}


	if (compareResearchScore(temp, newnode) == 2 || compareResearchScore(temp, newnode) == 3) { // this checks if the new node has priority over the head node. If it does, we need to set a new head
		if (compareResearchScore(temp, newnode) == 3)
		{
			if (compareCGPA(temp, newnode) == 3)
			{
				if (compareLocation(temp, newnode) == 2)
				{
					choice = 'H';
					return temp;
				}
			}
			else if (compareCGPA(temp, newnode) == 2)
			{
				choice = 'H';
				return temp;
			}

		}
		else
		{
			choice = 'H';
			return temp;
		}
	}//
	else
	{
		if (temp2 == nullptr) {
			temp2 = temp;
		}
		while (temp2->get_link() != nullptr && compareResearchScore(temp2, newnode) != 2 && compareResearchScore(temp2, newnode) != 3) { // our while loop traverses the linked list until the temp2 links to null or we find the place we want to insert the node


			temp = temp2; // both temp and temp2 traverse the list at the same time, but temp2 is one node ahead
			temp2 = temp2->get_link();

		}


		if (compareResearchScore(temp2, newnode) == 3) {

			while (temp2->get_link() != nullptr && compareCGPA(temp2, newnode) != 2 && compareCGPA(temp2, newnode) != 3 && compareResearchScore(temp2, newnode) == 3) {
				temp = temp2; // both temp and temp2 traverse the list at the same time, but temp2 is one node ahead
				temp2 = temp2->get_link();

			}
		}

		if (compareCGPA(temp2, newnode) == 3 && compareResearchScore(temp2, newnode) == 3) {

			while (temp2->get_link() != nullptr && compareLocation(temp2, newnode) != 2 && compareLocation(temp2, newnode) != 3 && compareResearchScore(temp2, newnode) == 3 && compareCGPA(temp2, newnode) == 3) {

				temp = temp2; // both temp and temp2 traverse the list at the same time, but temp2 is one node ahead
				temp2 = temp2->get_link();

			}

		}
	}
	// this if statement is really long, but basically it checks the last 2 nodes to determine if the new node should be a tail or not. The only reason it is long is because we are doing it based on the overall sort
	if (temp2->get_link() == nullptr && ((compareResearchScore(temp, newnode) == 1 && compareResearchScore(temp2, newnode) == 1)) || (compareResearchScore(temp2, newnode) == 3 && compareCGPA(temp2, newnode) == 1 && compareCGPA(temp, newnode) == 1) || (compareResearchScore(temp2, newnode) == 3 && compareCGPA(temp2, newnode) == 3 && compareLocation(temp2, newnode) == 1 && compareLocation(temp, newnode) == 1)) { // if temp2 links to null and the new node has less priority over the last 2 nodes, we need a new tail
		choice = 'T';
		return temp2;
	}
	else {
		choice = 'R'; // if not any of the other options, then the new node is a normal insert
		return temp;
	}



}

studentPtr monosearch(studentPtr &head, studentPtr &newnode, char& choice) // Function shows where the new node should be inserted, based on the overal sort
{
	// choice is a character variable that the user sends in, this tells us which type of insert we need
	studentPtr temp;
	studentPtr temp2 = nullptr;

	temp = head;

	if (temp != nullptr) { // First check if the list is empty or only has one node
		temp2 = temp->get_link(); // Our implementation always has 2 pointers - one(temp2) for testing to see where to sort and one to send to the insert(temp)
	}
	else {
		choice = 'B'; // if empty, we need to set both the head and tail to a new node
		return temp;
	}


	if (compareResearchScore(temp, newnode) == 2 || compareResearchScore(temp, newnode) == 3) { // this checks if the new node has priority over the head node. If it does, we need to set a new head
		if (compareResearchScore(temp, newnode) == 3)
		{
			if (compareCGPA(temp, newnode) == 3)
			{
				if (compareLocation(temp, newnode) == 2)
				{
					choice = 'H';
					return temp;
				}
			}
			else if (compareCGPA(temp, newnode) == 2)
			{
				choice = 'H';
				return temp;
			}

		}
		else
		{
			choice = 'H';
			return temp;
		}
	}//
	else
	{
		if (temp2 == nullptr) {
			temp2 = temp;
		}
		while (temp2->get_link() != nullptr && compareResearchScore(temp2, newnode) != 2 && compareResearchScore(temp2, newnode) != 3) { // our while loop traverses the linked list until the temp2 links to null or we find the place we want to insert the node


			temp = temp2; // both temp and temp2 traverse the list at the same time, but temp2 is one node ahead
			temp2 = temp2->get_link();

		}


		if (compareResearchScore(temp2, newnode) == 3) {

			while (temp2->get_link() != nullptr && compareCGPA(temp2, newnode) != 2 && compareCGPA(temp2, newnode) != 3 && compareResearchScore(temp2, newnode) == 3) {
				temp = temp2; // both temp and temp2 traverse the list at the same time, but temp2 is one node ahead
				temp2 = temp2->get_link();

			}
		}

		if (compareCGPA(temp2, newnode) == 3 && compareResearchScore(temp2, newnode) == 3) {

			while (temp2->get_link() != nullptr && compareLocation(temp2, newnode) != 2 && compareLocation(temp2, newnode) != 3 && compareResearchScore(temp2, newnode) == 3 && compareCGPA(temp2, newnode) == 3) {

				temp = temp2; // both temp and temp2 traverse the list at the same time, but temp2 is one node ahead
				temp2 = temp2->get_link();

			}

		}
	}
	// this if statement is really long, but basically it checks the last 2 nodes to determine if the new node should be a tail or not. The only reason it is long is because we are doing it based on the overall sort
	if (temp2->get_link() == nullptr && ((compareResearchScore(temp, newnode) == 1 && compareResearchScore(temp2, newnode) == 1)) || (compareResearchScore(temp2, newnode) == 3 && compareCGPA(temp2, newnode) == 1 && compareCGPA(temp, newnode) == 1) || (compareResearchScore(temp2, newnode) == 3 && compareCGPA(temp2, newnode) == 3 && compareLocation(temp2, newnode) == 1 && compareLocation(temp, newnode) == 1)) { // if temp2 links to null and the new node has less priority over the last 2 nodes, we need a new tail
		choice = 'T';
		return temp2;
	}
	else {
		choice = 'R'; // if not any of the other options, then the new node is a normal insert
		return temp;
	}



}

void insert(studentPtr stu, studentPtr& head, studentPtr& tail, studentPtr& newnode, const char& choice)
{
	studentPtr temp = newnode;

	// choice is based on the search function
	if (choice == 'R') //regular insert
	{
		temp->set_link(stu->get_link()); // temp links to what stu links to
		stu->set_link(temp); // stu's new link is temp

	}
	else if (choice == 'B') // head and tail insert
	{
		temp->set_link(nullptr); // temps link is null b/c the only time head and tail point to the same node is if there is only 1 node left
		head = temp;
		tail = temp;
	}
	else if (choice == 'H') // head insert
	{
		temp->set_link(head);
		head = temp;
	}
	else if (choice == 'T') // tail insert
	{

		stu->set_link(temp);
		temp->set_link(nullptr);
		tail = temp;
	}



}


void searchID(studentPtr head1, studentPtr head2, int num) // this function checks the entire list and prints out all the students with the id of 'num'
{
	studentPtr temp1; // we have temp1 and temp2 because the two lists are not merged yet
	studentPtr temp2;
	int counter = 0;
	temp1 = head1;
	temp2 = head2;
	if (temp1 == nullptr && temp2 == nullptr)
	{
		cout << "There is no student with the student number " << num << endl;
	}
	else
	{
		// we check the whole domestic student list for the student with the specific ID
		if (temp1 != nullptr)
		{
			while (temp1 != nullptr)
			{
				if (temp1->get_id() == num)
				{

					cout << *temp1;
					counter++;

				}
				temp1 = temp1->get_link();

			}
		}

		// we check the whole international student list for the student with the specific ID
		if (temp2 != nullptr)
		{
			while (temp2 != nullptr)
			{
				if (temp2->get_id() == num)
				{
					cout << *temp2;
					counter++;

				}
				temp2 = temp2->get_link();

			}
		}
	}
	if (counter == 0)
	{
		cout << "There is no student with the student number " << num << endl; // let the user know there are no students with id 'num''
	}
}
void searchCGPA(studentPtr head1, studentPtr head2, float num)// this function checks the entire list and prints out all the students with the cgpa of 'num'
{

	studentPtr temp1;  // we have temp1 and temp2 because the two lists are not merged yet
	studentPtr temp2;
	studentPtr temp3 = new Student(" ", " ", num, 100, 20200000); // we put the cgpa in temp3 so that we can use our compare functions

	int counter = 0;
	temp1 = head1;
	temp2 = head2;
	if (temp1 == nullptr && temp2 == nullptr)
	{
		cout << "There is no student with the CGPA " << num << endl;
	}
	else
	{
		if (temp1 != nullptr)
		{
			while (temp1 != nullptr)
			{
				if (compareCGPA(temp1, temp3) == 3)
				{

					cout << *temp1 << endl;
					counter++;

				}
				temp1 = temp1->get_link();

			}
		}
		if (temp2 != nullptr)
		{
			while (temp2 != nullptr)
			{
				if (compareCGPA(temp2, temp3) == 3)
				{
					cout << *temp2 << endl;
					counter++;
				}
				temp2 = temp2->get_link();

			}
		}
	}
	if (counter == 0)
	{
		cout << "There is no student with the CGPA " << num << endl;  // let the user know there are no students with cgpa 'num'
	}
}
void searchReScore(studentPtr head1, studentPtr head2, int num) // this function checks the entire list and prints out all the students with the research score of 'num'
{

	studentPtr temp1;
	studentPtr temp2;
	studentPtr temp3 = new Student(" ", " ", 4, num, 20200000);
	int counter = 0;
	temp1 = head1;
	temp2 = head2;
	if (temp1 == nullptr && temp2 == nullptr)
	{
		cout << "There is no student with the research score " << num << endl;
	}
	else
	{
		if (temp1 != nullptr)
		{
			while (temp1 != nullptr)
			{
				if (compareResearchScore(temp1, temp3) == 3)
				{
					cout << *temp1 << endl;
					counter++;
				}
				temp1 = temp1->get_link();

			}
		}
		if (temp2 != nullptr)
		{
			while (temp2 != nullptr)
			{
				if (compareResearchScore(temp2, temp3) == 3)
				{
					cout << *temp2 << endl;
					counter++;

				}
				temp2 = temp2->get_link();

			}
		}
	}
	if (counter == 0)
	{
		cout << "There is no student with the research score " << num << endl; // let the user know there are no students with research score 'num'
	}
}

void searchName(studentPtr head1, studentPtr head2, string first, string last) // for search name, the function checks both lists to make sure both first and last names are the same as the input, and then prints the student
{
	studentPtr temp1;
	studentPtr temp2;
	studentPtr temp3 = new Student(first, last, 4, 100, 20200000);
	int counter = 0;
	temp1 = head1;
	temp2 = head2;
	if (temp1 == nullptr && temp2 == nullptr)
	{

		cout << "There is no student with the name " << first << " " << last << endl;
	}

	else
	{
		if (temp1 != nullptr)
		{
			while (temp1 != nullptr)
			{
				if (compareFirstName(temp1, temp3) == 3 && compareLastName(temp1, temp3) == 3)
				{
					cout << *temp1 ;
					counter++;
				}
				temp1 = temp1->get_link();

			}
		}
		if (temp2 != nullptr)
		{
			while (temp2 != nullptr)
			{
				if (compareFirstName(temp2, temp3) == 3 && compareLastName(temp2, temp3) == 3)
				{
					cout << *temp2 ;
					counter++;

				}
				temp2 = temp2->get_link();

			}
		}
	}
	if (counter == 0)
	{
		cout << "There is no student with the name " << first << " " << last << endl;
	}
}



void Student::set_location(string prov) //Student class virtual functions of location, however, we never really use location ever
{
	location = prov;
}
string Student::get_location() const
{
	return location;
}
string DomesticStudent::type() const
{
	return "DomesticStudent";
}
string Student::type() const
{
	return "Student";
}

void InternationalStudent::set_location(string place) // International class virtual functions of location, sets and gets country instead of location
{
	if(place == "Idian")
	{
		cout << "TYPO: Idian \nAutocorrected to 'India'" << endl;
		country = "India";
	}
	else if(place != "Canada" && place != "China" && place != "India" && place != "Korea" && place != "Iran")
	{
		cerr << "ERROR: Invalid country entered" << endl;
		exit(14);
	}
	else
	{
		country = place;
	}
}
string InternationalStudent::get_location() const
{
	return country;
}
string InternationalStudent::type() const
{
	return "InternationalStudent";
}

void merge( studentPtr domlist,  studentPtr intlist, studentPtr &Head, studentPtr &Tail) {

	studentPtr temp = Head; // temporary pointer

	int counter = 0;


	while (domlist->get_link() != nullptr || intlist->get_link() != nullptr) {  //if any of the lists are not empty keep looking at the information


		if (counter == 0) { // this checks if the new node has priority over the head node. If it does, we need to set a new head
			if (domlist->get_link() == nullptr && intlist->get_link() == nullptr) {
				cerr << "Both lists are empty" << endl;

			}
			else if (domlist->get_link() == nullptr) { // if only domlist is empty the intlist becomes the head
				Head = intlist;
				temp = intlist;
				if (intlist->get_link() != nullptr) {
					intlist = intlist->get_link();
				}
				else {
					Tail = intlist;
				}
			}
			else if (intlist->get_link() == nullptr) {// if only intlist is empty the domlist becomes the head
				Head = domlist;
				temp = domlist;
				if (domlist->get_link() != nullptr) {
					domlist = domlist->get_link();
				}
				else {
					Tail = domlist;
				}
			}

			else if (compareResearchScore(domlist, intlist) == 1) { // if the domestic student research score is bigger than the international student then the domestic student becomes the head
				Head = domlist;
				temp = domlist;
				if (domlist->get_link() != nullptr) {
					domlist = domlist->get_link();
				}


			}
			else if (compareResearchScore(domlist, intlist) == 2) {  // if the international student research score is bigger than the domestic student then the international student becomes the head

				Head = intlist;
				temp = intlist;
				if (intlist->get_link()!= nullptr) {
					intlist = intlist->get_link();
				}
			}
			else {
				// if the domestic student and international student have the same research score we check the CGPA scores
				if (compareCGPA(domlist, intlist) == 1) {
					Head = domlist;
					temp = domlist;
					if (domlist->get_link() != nullptr) {// if the domestic student CGPA score is bigger than the international student's then the domestic student becomes the head
						domlist = domlist->get_link();
					}
				}
				else if (compareCGPA(domlist, intlist) == 2) {// if the international student CGPA score is bigger than the domestic student's then the international student becomes the head
					Head = intlist;
					temp = intlist;
					if (intlist->get_link()!= nullptr) {
						intlist = intlist->get_link();
					}
				}
				else { // if all the informationa is the same then put the domestic student as the head
					Head = domlist;
					temp = domlist;
					if (domlist->get_link()!= nullptr) {
						domlist = domlist->get_link();
					}

				}

			}


		}
		else if (domlist->get_link() == nullptr) {// if the domestic student list is empty then the rest of the list will be the international students
			temp->set_link(intlist);
			temp = intlist;

			if (intlist->get_link() != nullptr) {
				intlist = intlist->get_link();
			}
			else {
				Tail = intlist;
			}
		}
		else if (intlist->get_link() == nullptr) {// if the international student list is empty then the rest of the list will be the domestic students
			temp->set_link(domlist);
			temp = domlist;

			if (domlist->get_link() != nullptr) {
				domlist = domlist->get_link();
			}
			else {
				Tail = domlist;
			}
		}
		else {

			if (compareResearchScore(domlist, intlist) == 1) { // if the domestic student research score is bigger than the international student's then the domestic student goes first

				temp->set_link(domlist);
				temp = domlist;

				if (domlist->get_link() != nullptr) {
					domlist = domlist->get_link();
				}

			}
			else if (compareResearchScore(domlist, intlist) == 2) { // if the internationl student research score is bigger than the domestic student's then the international student goes first

				temp->set_link(intlist);
				temp = intlist;

				if (intlist->get_link() != nullptr) {
					intlist = intlist->get_link();
				}
			}
			else {

				if (compareCGPA(domlist, intlist) == 1) { // if the domestic student CGPA score is bigger than the international student's then the domestic student goes first
					temp->set_link(domlist);
					temp = domlist;

					if (domlist->get_link() != nullptr) {
						domlist = domlist->get_link();
					}
				}
				else if (compareCGPA(domlist, intlist) == 2) { // if the internationl student CGPA score is bigger than the domestic student's then the international student goes first
					temp->set_link(intlist);
					temp = intlist;

					if (intlist->get_link() != nullptr) {
						intlist = intlist->get_link();
					}
				}
				else { // if all the informationa is the same then the domestic student goes first
					temp->set_link(domlist);
					temp = domlist;

					if (domlist->get_link() != nullptr) {
						domlist = domlist->get_link();
					}
				}
			}

		}

		counter++;
	}
}


void deleteStudent(studentPtr &head, studentPtr &tail, studentPtr &beforeDelete, char& choice) // this function deletesa student based on the character 'choice'
{
	if (head == nullptr)
	{
		cout << "This list is empty!" << endl;
	}
	else
	{
		if (head == tail)
		{
			choice = 'B';
		}
		studentPtr temp = beforeDelete->get_link();
		// choice is based on the search function
		if (choice == 'R') //regular delete
		{
			beforeDelete->set_link(temp->get_link()); // beforeDelete links to what temp links to
			temp->set_link(nullptr); // set temp link to null just in case
			delete temp; // delete the node

		}
		else if (choice == 'B') // delete the last node in a list
		{
			temp = head; // this assuemes there is only one more node left in the list
			delete temp;
			head = nullptr;
			tail = nullptr;
			beforeDelete = nullptr;
		}
		else if (choice == 'H') // head delete
		{
			head = head->get_link();
			temp = beforeDelete;
			temp->set_link(nullptr);
			beforeDelete = head;
			delete temp;
		}
		else if (choice == 'T') // tail delete
		{
			tail = beforeDelete;
			beforeDelete->set_link(nullptr);
			temp->set_link(nullptr);
			delete temp;
		}
		else if (choice == 'b') // delete both head and tail at the same time
		{
			head = head->get_link();
			temp = beforeDelete;
			temp->set_link(nullptr);
			beforeDelete = head;
			delete temp;

			while (beforeDelete->get_link() != tail)
			{
				beforeDelete = beforeDelete->get_link();
			}
			temp = tail;
			tail = beforeDelete;
			beforeDelete->set_link(nullptr);
			temp->set_link(nullptr);
			delete temp;
		}
	}

}

studentPtr deleteSearch(studentPtr head, studentPtr temphead, char& choice, string first, string last) // this function checks to see if any nodes match the input for deleting
{

	studentPtr temp = temphead; // temphead exist so that when the program deletes more than 1 node, it doesn't have to search from the very beginning all over again
	studentPtr temp2 = new Student(first, last, 4, 100, 20200000);
	studentPtr temp3 = nullptr;
	studentPtr temp4 = head;

	if (temp == nullptr)
	{
		return nullptr; // this means the list is empty
	}
	else {
		temp3 = temp->get_link(); // here we also have 2 pointers traversing the list, b/c we need to return the node before the delete, not the actual node to be deleted
	}

	if (head->get_link() == nullptr && compareFirstName(temp2, head) == 3 && compareLastName(temp2, head) == 3) // assuming there is only one node left in the list
	{
		choice = 'B';
		return temp4;
	}

	else if (compareFirstName(temp2, head) == 3 && compareLastName(temp2, head) == 3) {// this one always checks head, not temphead
		choice = 'H';
		return temp;
	}




	while (temp3 != nullptr)
	{
		if (temp3->get_link() == nullptr && compareFirstName(temp3, temp2) == 3 && compareLastName(temp3, temp2) == 3)
		{
			choice = 'T';
			return temp;

		}

		else if (compareFirstName(temp3, temp2) == 3 && compareLastName(temp3, temp2) == 3)
		{
			choice = 'R';
			return temp;
		}

		temp = temp3;
		temp3 = temp3->get_link();


	}


		return nullptr;



}

void threshold(studentPtr head, float cgpa, int research) // this function takes in a user inputted cgpa and research score for cheking which students can be admitted into SFU
{
	cout << "These students are admitted into SFU!" << endl;

	studentPtr temp = head;

	int counter = 0;
	temp = head;


	if (temp == nullptr)
	{
		cout << "No students admitted" << endl;
	}
	else
	{
		while (temp != nullptr)
		{
			if (temp->get_cgpa() >= cgpa && temp->get_reScore() >= research)
			{

				cout << *temp;
				counter++;

			}
			temp = temp->get_link();

		}

	}
	if(counter == 0)
	{
		cout << "No students admitted" << endl;
	}
}
// checkline makes sure the data in a line from the txt file has the proper data
bool checklineD(string &line)
{
	int counter = 0;
	for(int i = 0; i<line.length(); i++)
	{
		if(string.at(i)==",")
		{
			counter++;
		}
	}
	if (counter != 4)
	{
		cerr << "ERROR: line does not contain the right amount of fields" << endl;
		return true;
	}
	else
	{
		return false;
	}
}
bool checklineI(string &line)
{
	int counter = 0;
	for(int i = 0; i<line.length(); i++)
	{
		if(string.at(i)==",")
		{
			counter++;
		}
	}
	if (counter != 8)
	{
		cerr << "ERROR: line does not contain the right amount of fields" << endl;
		return true;
	}
	else
	{
		return false;
	}
}
