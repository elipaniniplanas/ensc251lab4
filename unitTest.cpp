//unitTest.cpp
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <iomanip>
#include "student.hpp"
#include<stdio.h>

void testInsert(studentPtr, studentPtr, int) const;
void testSearchData();
void testSearchName();
void testDeleteSearch();
void testDeleteEnds();
void testMerge();
void testSearchMerge();

int main()
{
  char retry;
  string userin;
  string line;
  int stu_num;
	ifstream domesticFile("domestic-stu.txt");
	if (!domesticFile.is_open()) {
		cout << "Unable to open file domestic-stu.txt" << endl;
		return -1;
	}
  while (getline(dTestFile, line)) {
		if(checklineD(line))
		{
		return -1;
		}
		istringstream ss(line);
		string firstName, lastName, province, s_cgpa, s_researchScore;
		float cgpa;
		int researchScore;
		//get firstName separated by comma
		getline(ss, firstName, ',');
		//get lastName separated by comma
		getline(ss, lastName, ',');
		//get province separated by comma
		getline(ss, province, ',');
		//get cpga separated by comma, and convert string to float
		getline(ss, s_cgpa, ',');
		cgpa = atof(s_cgpa.c_str());
		//get researchScore separated by comma, and convert it to int
		getline(ss, s_researchScore, ',');
		researchScore = atoi(s_researchScore.c_str());
		studentPtr inDom = new DomesticStudent(firstName, lastName, cgpa, researchScore, stu_num + 20200000, province);
		insert((search(domHead, inDom, sortDom)), domHead, domTail, inDom, sortDom);
		stu_count++;
		stu_num++;
	}
	dTestFile.close();
  while (getline(iTestFile, line)) {
		if(checklineI(line))
 		{
 			return -1;
 		}
		istringstream ss(line);
		string firstName, lastName, Country, s_cgpa, s_researchScore, s_Reading, s_Listening, s_Speaking, s_Writing;
		float cgpa;
		int researchScore;
		int toeflReading;
		int toeflListening;
		int toeflSpeaking;
		int toeflWriting;
		getline(ss, firstName, ',');
		getline(ss, lastName, ',');
		getline(ss, Country, ',');
		getline(ss, s_cgpa, ',');
		cgpa = atof(s_cgpa.c_str());
		getline(ss, s_researchScore, ',');
		researchScore = atoi(s_researchScore.c_str());
		getline(ss, s_Reading, ',');
		toeflReading = atoi(s_Reading.c_str());
		getline(ss, s_Listening, ',');
		toeflListening = atoi(s_Listening.c_str());
		getline(ss, s_Speaking, ',');
		toeflSpeaking = atoi(s_Speaking.c_str());
		getline(ss, s_Writing, ',');
		toeflWriting = atoi(s_Writing.c_str());

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		// Error Checking for InternationalStudent. If their scores are not high enough, they are dropped from the array
		if ((toeflListening + toeflReading + toeflWriting + toeflSpeaking) < 93 || toeflReading < 20 || toeflListening < 20 || toeflWriting < 20 || toeflSpeaking < 20)
		{
			continue;
		}
		studentPtr inInt = new InternationalStudent(firstName, lastName, cgpa, researchScore, stu_num + 20200000, Country, toeflReading, toeflListening, toeflSpeaking, toeflWriting);
		insert((search(intHead, inInt, sortInt)), intHead, intTail, inInt, sortInt);
		stu_num++;
		stu_count++;
	}
  iTestFile.close();


  do {
    cout<<"Test the insert funciton? [Y] yes, [Anything else] no"<<endl;
    cin>>userin;
    if(userin == "y" || userin == "Y")
      testInsert();
    userin = "p";
    cout<<"Test the search by data funcitons? [Y] yes, [Anything else] no"<<endl;
    cin>>userin;
    if(userin == "y" || userin == "Y")
      testSearchData();
    userin = "p";
    cout<<"Test the search by name funcitons? [Y] yes, [Anything else] no"<<endl;
    cin>>userin;
    if(userin == "y" || userin == "Y")
      testSearchName();
    userin = "p";
    cout<<"Test the delete student funciton? [Y] yes, [Anything else] no"<<endl;
    cin>>userin;
    if(userin == "y" || userin == "Y")
      testDeleteSearch();
    userin = "p";
    cout<<"Test the delete head and tail funciton? [Y] yes, [Anything else] no"<<endl;
    cin>>userin;
    if(userin == "y" || userin == "Y")
      testDeleteEnds();
    userin = "p";
    cout<<"Test the merge funciton? [Y] yes, [Anything else] no"<<endl;
    cin>>userin;
    if(userin == "y" || userin == "Y")
      testMerge();
    userin = "p";
    cout<<"Test the search merge funciton? [Y] yes, [Anything else] no"<<endl;
    cin>>userin;
    if(userin == "y" || userin == "Y")
      testSearchMerge();
    cout<<"Perform the unit test again? [Y] yes, [Anything else] no"<<endl;
    cin>>retry;
  } while(retry == "y");

  return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void testInsertDom(studentPtr domhead, studentPtr domtail, int stu_num) const
{
  studentPtr sortInt, sortDom;
  cout<<"Testing the normal case"<<endl;
  studentPtr inDom = new DomesticStudent("Lucy", "Pevensie", 4.00, 90, stu_num + 20200000, "BC");
  insert((monosearch(domHead, inDom, sortDom)), domHead, domTail, inDom, sortDom);
  if(head == NULL)
  {
    cerr<<"Insertion test failed"<<endl;
    retrun false;
  }
  temp = domHead
  temp2 = temp;
  temp2 = temp2->get_link();
  while(temp2!=nullptr)
  {
    if((compareResearchScore(temp, temp2) == 2)||((compareResearchScore(temp, temp2) == 3) && (compareCGPA(temp, temp2 == 2)))||((compareResearchScore(temp, temp2))&&(compareCGPA(temp, temp2))&&(compareLocation(temp, temp2))))
    {
      cerr<<"Insertion test failed"<<endl;
      return false;
    }
    temp = temp2; // both temp and temp2 traverse the list at the same time, but temp2 is one node ahead
    temp2 = temp2->get_link();
  }
  cout<<"Passed normal case insertion test"<<endl;
  cout<<"Testing the illegal case"<<endl;
  studentPtr illDom = new InternationalStudent("Div", "Yam", 4.00, 90, stu_num + 20200000, "Idian", 24, 25, 29, 26);
  stu_num++;
  insert((monosearch(domHead, illDom, sortDom)), domHead, domTail, illDom, sortDom);
  if(head == NULL)
  {
    cerr<<"Insertion test failed"<<endl;
    retrun false;
  }
  temp = domHead
  temp2 = temp;
  temp2 = temp2->get_link();
  while(temp2!=nullptr)
  {
    if((compareResearchScore(temp, temp2) == 2)||((compareResearchScore(temp, temp2) == 3) && (compareCGPA(temp, temp2 == 2)))||((compareResearchScore(temp, temp2))&&(compareCGPA(temp, temp2))&&(compareLocation(temp, temp2))))
    {
      cerr<<"Insertion test failed"<<endl;
      return false;
    }
    temp = temp2; // both temp and temp2 traverse the list at the same time, but temp2 is one node ahead
    temp2 = temp2->get_link();
  }
  cout<<"Passed illegal case insertion test"<<endl;
  cout<<"Testing the border case #1"<<endl;
  studentPtr illDom = new DomesticStudent("Susan", "Pevensie", 4.00, 100, stu_num + 20200000, "BC");
  stu_num++;
  insert((monosearch(domHead, illDom, sortDom)), domHead, domTail, illDom, sortDom);
  if(head == NULL)
  {
    cerr<<"Insertion test failed"<<endl;
    retrun false;
  }
  temp = domHead
  temp2 = temp;
  temp2 = temp2->get_link();
  while(temp2!=nullptr)
  {
    if((compareResearchScore(temp, temp2) == 2)||((compareResearchScore(temp, temp2) == 3) && (compareCGPA(temp, temp2 == 2)))||((compareResearchScore(temp, temp2))&&(compareCGPA(temp, temp2))&&(compareLocation(temp, temp2))))
    {
      cerr<<"Insertion test failed"<<endl;
      return false;
    }
    temp = temp2; // both temp and temp2 traverse the list at the same time, but temp2 is one node ahead
    temp2 = temp2->get_link();
  }
  cout<<"Passed border case #1 insertion test"<<endl;
  cout<<"Testing the border case #2"<<endl;
  studentPtr illDom = new DomesticStudent("Edward", "Pevensie", 4.00, 0, stu_num + 20200000);
  insert((search(domHead, illDom, sortDom)), domHead, domTail, illDom, sortDom);
  if(head == NULL)
  {
    cerr<<"Insertion test failed"<<endl;
    retrun false;
  }
  temp = domHead
  temp2 = temp;
  temp2 = temp2->get_link();
  while(temp2!=nullptr)
  {
    if((compareResearchScore(temp, temp2) == 2)||((compareResearchScore(temp, temp2) == 3) && (compareCGPA(temp, temp2 == 2)))||((compareResearchScore(temp, temp2))&&(compareCGPA(temp, temp2))&&(compareLocation(temp, temp2))))
    {
      cerr<<"Insertion test failed"<<endl;
      return false;
    }
    temp = temp2; // both temp and temp2 traverse the list at the same time, but temp2 is one node ahead
    temp2 = temp2->get_link();
  }
  cout<<"Passed border case #2 insertion test"<<endl;

  return true;
}
void testSearchData()
{}
void testSearchName()
{}
void testDeleteSearch()
{}
void testDeleteEnds()
{}
void testMerge()
{}
void testSearchMerge()
{}
