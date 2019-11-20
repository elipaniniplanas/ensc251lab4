#include "linkedListStudent.hpp"
#include <iostream>
#include <iomanip>
#include <string>



//default constructor
StudentList::StudentList() {
	this->nextNode = NULL;
}

int compareListResearchScore(StudentList* student1, StudentList* student2) {
	int n1, n2;
	//create student objects to see which type student1 and student 2 is  if they match that means its the opposite.
	DomesticStudent emptyDomesticStudent;
	InternationalStudent emptyInternationalStudent;

	if (student1->domStudent == emptyDomesticStudent) {
		n1 = student1->intStudent.get_researchscore();
	}
	if (student1->intStudent == emptyInternationalStudent) {
		n1 = student1->domStudent.get_researchscore();
	}

	if (student2->domStudent == emptyDomesticStudent) {
		n2 = student2->intStudent.get_researchscore();
	}
	if (student2->intStudent == emptyInternationalStudent) {
		n2 = student2->domStudent.get_researchscore();
	}


	if (n1 > n2) return 1;
	if (n1 < n2) return -1;
	return 0;
}
int compareListLocation(StudentList* student1, StudentList* student2) {
	string temp1, temp2;
	//create student objects to see which type student1 and student 2 is  if they match that means its the opposite.
	DomesticStudent emptyDomesticStudent;
	InternationalStudent emptyInternationalStudent;

	if (student1->domStudent == emptyDomesticStudent) {
		temp1 = student1->intStudent.get_country();
	}
	if (student1->intStudent == emptyInternationalStudent) {
		temp1 = student1->domStudent.get_province();
	}

	if (student2->domStudent == emptyDomesticStudent) {
		temp2 = student2->intStudent.get_country();
	}
	if (student2->intStudent == emptyInternationalStudent) {
		temp2 = student2->domStudent.get_province();
	}
	//makes strings all capital letters for more reliable comparison
	for (int i = 0; i < temp1.size(); i++) if (temp1[i] >= 'a' && temp1[i] <= 'z') temp1[i] -= ('a' - 'A');
	for (int i = 0; i < temp2.size(); i++) if (temp2[i] >= 'a' && temp2[i] <= 'z') temp2[i] -= ('a' - 'A');
	if(temp1 > temp2) return -1;
	else if (temp1 == temp2) return 0;
	else return 1;

	//return temp2.compare(temp1);
}
int compareListFirstName(StudentList* student1, StudentList* student2) {
	string temp1, temp2;
	//create student objects to see which type student1 and student 2 is  if they match that means its the opposite.
	DomesticStudent emptyDomesticStudent;
	InternationalStudent emptyInternationalStudent;

	if (student1->domStudent == emptyDomesticStudent) {
		temp1 = student1->intStudent.get_firstname();
	}
	if (student1->intStudent == emptyInternationalStudent) {
		temp1 = student1->domStudent.get_firstname();
	}

	if (student2->domStudent == emptyDomesticStudent) {
		temp2 = student2->intStudent.get_firstname();
	}
	if (student2->intStudent == emptyInternationalStudent) {
		temp2 = student2->domStudent.get_firstname();
	}
	//makes strings all capital letters for more reliable comparison
	for (int i = 0; i < temp1.size(); i++) if (temp1[i] >= 'a' && temp1[i] <= 'z') temp1[i] -= ('a' - 'A');
	for (int i = 0; i < temp2.size(); i++) if (temp2[i] >= 'a' && temp2[i] <= 'z') temp2[i] -= ('a' - 'A');
	return temp2.compare(temp1);
}
int compareListLastName(StudentList* student1, StudentList* student2) {
	string temp1, temp2;
	//create student objects to see which type student1 and student 2 is  if they match that means its the opposite.
	DomesticStudent emptyDomesticStudent;
	InternationalStudent emptyInternationalStudent;

	if (student1->domStudent == emptyDomesticStudent) {
		temp1 = student1->intStudent.get_lastname();
	}
	if (student1->intStudent == emptyInternationalStudent) {
		temp1 = student1->domStudent.get_lastname();
	}

	if (student2->domStudent == emptyDomesticStudent) {
		temp2 = student2->intStudent.get_lastname();
	}
	if (student2->intStudent == emptyInternationalStudent) {
		temp2 = student2->domStudent.get_lastname();
	}
	//makes strings all capital letters for more reliable comparison
	for (int i = 0; i < temp1.size(); i++) if (temp1[i] >= 'a' && temp1[i] <= 'z') temp1[i] -= ('a' - 'A');
	for (int i = 0; i < temp2.size(); i++) if (temp2[i] >= 'a' && temp2[i] <= 'z') temp2[i] -= ('a' - 'A');
	return temp2.compare(temp1);

}
int compareListCGPA(StudentList* student1, StudentList* student2) {
	float n1, n2;
	//create student objects to see which type student1 and student 2 is  if they match that means its the opposite.
	DomesticStudent emptyDomesticStudent;
	InternationalStudent emptyInternationalStudent;
	if (student1->domStudent == emptyDomesticStudent) {
		n1 = student1->intStudent.get_cgpa();
	}
	if (student1->intStudent == emptyInternationalStudent) {
		n1 = student1->domStudent.get_cgpa();
	}

	if (student2->domStudent == emptyDomesticStudent) {
		n2 = student2->intStudent.get_cgpa();
	}
	if (student2->intStudent == emptyInternationalStudent) {
		n2 = student2->domStudent.get_cgpa();
	}
	if (n1 > n2) return 1;
	if (n1 < n2) return -1;
	return 0;

}

