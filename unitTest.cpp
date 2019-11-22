//unitTest.cpp
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <iomanip>
#include "student.hpp"
#include<stdio.h>

void testInsert();
void testSearch()


int main()
{
  char searchchoice;
  string line;
	ifstream domesticFile("domestic-stu.txt");
	if (!domesticFile.is_open()) {
		cout << "Unable to open file domestic-stu.txt" << endl;
		return -1;
	}
  while (getline(domesticFile, line)) {
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
	domesticFile.close();
  int userIn1;
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

  cout<<"Select which funciton to be tested:\n[1] Insert\n[2] Search\n[3] Delete\n[4] Merge & Search"<<endl;
  cin>>userIn1;
  if(userIn1<=0 || userIn1>4)
  {
			cerr << "ERROR: Please select a proper option" << endl;
			userIn1 = 0;
			continue;
  }
  else if (userIn1 == 4)
  {
    testMerge();
    break;
  }
  else if (userIn1 == 3)
  {
    while(deletechoice == 'y'|| deletechoice == 'Y')
    {
      int userIn2;
      cout << "Select which delete function to be tested:\n[1] Delete head and tail nodes\n[2] Delete students based on a name" << endl;
      cin>>userIn2;
      if(userIn2<=0 || userIn2>2)
      {
        cerr << "ERROR: Please select a proper option" << endl;
        userIn1 = 0;
        continue;
      }
      // search function
      if (userIn2 == 1)
      {
        testdeletestudent();
      }
      else if (userIn2 == 2)
      {
        cout << "Please enter the first name you would like to find"<< endl;
        cin >> firstname;
        cout << "Please enter the last name you would like to find"<< endl;
        cin >> lastname;

        testdeleteSearch();
      }
      cout << endl;
      cout << "would you like to test delete again?"<<endl;
      cout << "press y to test" << endl;
      cin >> deletechoice;

      if (deletechoice != 'y' && deletechoice != 'Y')
      {
        break;
      }
      else
      {
        cout << endl;
        continue;
      }
    }

  }
  else if (userIn1 == 2)
  {
  while(searchchoice == 'y'|| searchchoice == 'Y')
    {
      cout << "what kind of search would you like to do? "<< endl;
      cout << "[N] Full Name " << endl;
      cout << "[C] CGPA" << endl << "[R] Research Score " << endl;
      cout << "[I] Student ID" << endl;

      cout << "Choice: " << endl;
      cin >> userIn3;
      if (userIn3 != 'n' && userIn3 != 'N' && userIn3 != 'c' && userIn3 != 'C' && userIn3 != 'r' && userIn3 != 'R' && userIn3 != 'I' && userIn3 != 'i' || cin.peek() != '\n')
      {
        cerr << "ERROR: Please select a proper searching category" << endl;
        userIn3 = 'p';
        continue;
      }
      // SEARCH FUNCTIONS

      if (searchType == 'I' || searchType == 'i')
      {
        cout << "Please enter the ID you would like to find" << endl;
        cin >> idChoice;
        testsearchID();
      }
      else if (searchType == 'c' || searchType == 'C')
      {
        cout << "Please enter the CGPA you would like to find" << endl;
        cin >> cgpaChoice;
        testsearchCGPA();
      }
      else if (searchType == 'r' || searchType == 'R')
      {
        cout << "Please enter the research score you would like to find" << endl;
        cin >> rChoice;
        testsearchReScore();
      }
      else if (searchType == 'n' || searchType == 'N')
      {
        cout << "Please enter the first name you would like to find" << endl;
        cin >> firstname;
        cout << endl;
        cout << "Please enter the last name you would like to find" << endl;
        cin >> lastname;
        cout << endl;

        testsearchName();
      }

      cout << endl;
      cout << "Would you like to search again?" << endl;
      cout << "press 'y' to search again:  ";
      cin >> searchchoice;

      if (searchchoice != 'y' && searchchoice != 'Y')
      {
        break;
      }
      else
      {
        cout << endl;
        continue;
      }
    }
  }
  else if (userIn1 == 1)
  {
    testinsert();
  }
  return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool testInsertDom(studentPtr domhead, studentPtr domtail, int stu_num)
{
  cout<<"Testing the normal case"<<endl;
  studentPtr inDom = new DomesticStudent("Lucy", "Pevensie", 4.00, 90, stu_num + 20200000, "BC");
  insert((search(domHead, inDom, sortDom)), domHead, domTail, inDom, sortDom);
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
  cout<<"Passed insertion test"<<endl;
  cout<<"Testing the illegal case"<<endl;
  studentPtr illDom = new DomesticStudent("Lucy", "Pevensie", 4.00, 90, stu_num + 20200000);
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

  return true;
}
void test
