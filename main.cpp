//main.cpp, put your driver code here,
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <iomanip>
#include "student.hpp"
#include<stdio.h>

int main() {

	char sortDom = 'p';
	char sortInt = 'p';

	typedef Student* studentPtr;
	typedef DomesticStudent* domesticStudentPtr;
	typedef InternationalStudent* internationalStudentPtr;

	studentPtr head;
	studentPtr domHead;
	studentPtr domTail;

	studentPtr tail;
	studentPtr intHead;
	studentPtr intTail;

	domHead = nullptr;
	domTail = nullptr;
	intHead = nullptr;
	intTail = nullptr;

	//Read the domestic-stu.txt file and exit if failed
	string line;
	ifstream domesticFile("domestic-stu.txt");
	if (!domesticFile.is_open()) {
		cout << "Unable to open file domestic-stu.txt" << endl;
		return -1;
	}

	//Read the first line of domestic-stu.txt, which specifies
	//the file format. And then print it out to the screen

	getline(domesticFile, line);

	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << setw(15) << left << "First Name"
		<< setw(15) << left << "Last Name"
		<< setw(15) << left << "Province"
		<< setw(10) << left << "CGPA"
		<< setw(18) << left << "Research Score"
		<< setw(15) << left << "Student Number"  << endl;
	cout << "------------------------------------------------------------------------------------------------" << endl;
	int stu_count = 0;
	int stu_num = 0;

	while (getline(domesticFile, line)) {

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

	studentPtr tempdom;
	tempdom = domHead;
	while (tempdom != nullptr)
	{
		cout << *tempdom;
		tempdom = tempdom->get_link();
	}



	//close your file
	domesticFile.close();

	cout << endl;


	//Read the domestic-stu.txt file and exit if failed
	ifstream internationalFile("international-stu.txt");
	if (!internationalFile.is_open()) {
		cout << "Unable to open file international-stu.txt" << endl;
		return -1;
	}


	//Read the first line of domestic-stu.txt, which specifies
	//the file format. And then print it out to the screen
	getline(internationalFile, line);



	stu_count = 0;
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << setw(15) << left << "First Name"
		<< setw(15) << left << "Last Name"
		<< setw(15) << left << "Country"
		<< setw(10) << left << "CGPA"
		<< setw(18) << left << "Research Score"
		<< setw(18) << left << "Student Number"
		<< setw(10) << left << "Total"
		<< setw(10) << left << "Reading"
		<< setw(10) << left << "Listening"
		<< setw(10) << left << "Speaking"
		<< setw(10) << left << "Writing"  << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	while (getline(internationalFile, line)) {

		/*process each line, get each field separated by a comma.
		 *We use istringstream to handle it.
		 *Note in this example code here, we assume the file format
		 *is perfect and do NOT handle error cases. We will leave the
		 *error and exception handling of file format to Lab Assignment 4
		 */
		istringstream ss(line);

		string firstName, lastName, Country, s_cgpa, s_researchScore, s_Reading, s_Listening, s_Speaking, s_Writing;
		float cgpa;
		int researchScore;
		int toeflReading;
		int toeflListening;
		int toeflSpeaking;
		int toeflWriting;

		//get firstName separated by comma
		getline(ss, firstName, ',');

		//get lastName separated by comma
		getline(ss, lastName, ',');

		//get province separated by comma
		getline(ss, Country, ',');

		//get cpga separated by comma, and convert string to float
		getline(ss, s_cgpa, ',');
		cgpa = atof(s_cgpa.c_str());

		//get researchScore separated by comma, and convert it to int
		getline(ss, s_researchScore, ',');
		researchScore = atoi(s_researchScore.c_str());

		//get toefl reading score
		getline(ss, s_Reading, ',');
		toeflReading = atoi(s_Reading.c_str());

		//get toefl Listening score
		getline(ss, s_Listening, ',');
		toeflListening = atoi(s_Listening.c_str());

		//get toefl Speaking score
		getline(ss, s_Speaking, ',');
		toeflSpeaking = atoi(s_Speaking.c_str());

		//get toefl Listening score
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
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	studentPtr tempint;
	tempint = intHead;
	while (tempint != nullptr)
	{
		cout << *tempint;
		tempint = tempint->get_link();
	}

	cout << endl;

	int homeChoice = 0;
	char gotoHome = 'y';
	// INTERFACE
	while (gotoHome == 'y' || gotoHome == 'Y') //This while loop is for asking the user if they want to come back to homepage
	{
		gotoHome = 'n';
		char searchAgain = 'y';
		char addAnother = 'y';
		char deleteAnother = 'y';
		char searchType = 'p';
		char studType = 'p';
		int idChoice = 0;

		string firstname = "";
		string lastname = "";


		cout << "Welcome to SFU! What would you like to do today?" << endl;

		cout << "[1] Search for a Student" << endl;
		cout << "[2] Add a Student" << endl;
		cout << "[3] Delete a Student" << endl;
		cout << "[4] Merge Lists" << endl;
		cout << "[5] Exit Program" << endl;

		cout << "Choice: ";
		cin >> homeChoice;
		cout << endl;

		if (homeChoice > 5 || homeChoice <= 0)
		{
			cerr << "ERROR: Please select a proper option" << endl;
			homeChoice = 0;


			continue;
		}

		if (homeChoice == 5) // EXIT
		{
			break;
		}
		else if (homeChoice == 4) // MERGE
		{
			break;
		}
		else if (homeChoice == 1)
		{
			//////////////////////////////////////////////////////////////////////////SEARCHING////////////////////////////////////////////////////////
			while (searchAgain == 'y' || searchAgain == 'Y')
			{
				idChoice = 'p';
				float cgpaChoice = 0;
				firstname = "";
				string lastname = "";
				cout << "What would you like to search?" << endl;
				cout << "[N] Full Name " << endl;
				cout << "[C] CGPA" << endl << "[R] Research Score " << endl;
				cout << "[I] Student ID" << endl;

				cout << "Choice: ";
				cin >> searchType;
				cout << endl;

				if (searchType != 'n' && searchType != 'N' && searchType != 'c' && searchType != 'C' && searchType != 'r' && searchType != 'R' && searchType != 'I' && searchType != 'i' || cin.peek() != '\n')
				{
					cerr << "ERROR: Please select a proper searching category" << endl;
					searchType = 'p';


					continue;
				}
				// SEARCH FUNCTIONS

				if (searchType == 'I' || searchType == 'i')
				{
					cout << "Please enter the ID you would like to find" << endl;
					cin >> idChoice;
					searchID(domHead, intHead, idChoice);
				}
				else if (searchType == 'c' || searchType == 'C')
				{
					cout << "Please enter the CGPA you would like to find" << endl;
					cin >> cgpaChoice;
					searchCGPA(domHead, intHead, cgpaChoice);
				}
				else if (searchType == 'r' || searchType == 'R')
				{
					cout << "Please enter the research score you would like to find" << endl;
					cin >> idChoice;
					searchReScore(domHead, intHead, idChoice);
				}
				else if (searchType == 'n' || searchType == 'N')
				{
					cout << "Please enter the first name you would like to find" << endl;
					cin >> firstname;
					cout << endl;
					cout << "Please enter the last name you would like to find" << endl;
					cin >> lastname;
					cout << endl;

					searchName(domHead, intHead, firstname, lastname);

				}

				cout << endl;
				cout << "Would you like to search again?" << endl;
				cout << "press 'y' to search again:  ";
				cin >> searchAgain;

				if (searchAgain != 'y' && searchAgain != 'Y')
				{
					break;
				}
				else
				{
					cout << endl;

					continue;
				}

			}
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		}
		else if (homeChoice == 2)
		{
			//////////////////////////////////////////////////////////////////////////INSERT NEW STUDENTS////////////////////////////////////////////////////////
			while (addAnother == 'y' || addAnother == 'Y')
			{
				cout << "Pick your student type" << endl;
				cout << "[D] Domestic" << endl;
				cout << "[I] International" << endl;

				cout << "Choice: ";
				cin >> studType;
				cout << endl;

				if (studType != 'd' && studType != 'D' && studType != 'i' && studType != 'I' || cin.peek() != '\n')
				{
					cerr << "ERROR: Please select a proper student type" << endl;
					studType = 'p';


					continue;
				}

				if (studType == 'd' || studType == 'D')
				{
					string firstName, lastName, province = "";
					float cgpa = -1;
					int researchScore = -1;


					cout << "Please enter the student's first name" << endl;
					cin >> firstName;
					cout << endl;

					cout << "Please enter the student's last name" << endl;
					cin >> lastName;
					cout << endl;


						cout << "Please enter the student's CGPA" << endl;
						cin >> cgpa;
						cout << endl;




						cout << "Please enter the student's research score" << endl;
						cin >> researchScore;
						cout << endl;




						cout << "Please enter the student's province" << endl;
						cin >> province;





						if (cgpa < 0 || cgpa>4.33) {
							cerr << "Invalid CGPA. CGPA must be between 0 and 4.33\nThe student will not be considered\n";
						}
						else if (researchScore < 0 || researchScore>100) {
							cerr << "Invalid research score. Research scores must be between 0 and 100\nThe student will not be considered\n";
						}
						else if (province != "BC" && province != "AB" & province != "ON" & province != "MB" && province != "NB" && province != "NL" && province != "YT" && province != "SK" && province != "NU" && province != "NS" && province != "QC" && province != "NT" && province != "NU" && province != "PE") {
							cerr << "Invalid Province. \nPlease make sure the provinces are in their proper acronyms \nChoices:BC, AB, ON, MB, NB, NL, YT, SK, NU, NS, QC, NT, PE\nThe student will not be considered\n";
						}
						else {
							studentPtr inDom = new DomesticStudent(firstName, lastName, cgpa, researchScore, stu_num + 20200000, province);
							insert((search(domHead, inDom, sortDom)), domHead, domTail, inDom, sortDom);



							studentPtr tempdom = new DomesticStudent;
							tempdom = domHead;
							while (tempdom != nullptr)
							{
								cout << *tempdom;
								tempdom = tempdom->get_link();
							}
						}


				}
				else
				{
					string firstName, lastName, Country = "";
					float cgpa = -1;
					int researchScore = -1;
					int toeflReading = -1;
					int toeflListening = -1;
					int toeflSpeaking = -1;
					int toeflWriting = -1;


					cout << "Please enter the student's first name" << endl;
					cin >> firstName;
					cout << endl;

					cout << "Please enter the student's last name" << endl;
					cin >> lastName;
					cout << endl;


						cout << "Please enter the student's CGPA" << endl;
						cin >> cgpa;
						cout << endl;




						cout << "Please enter the student's research score" << endl;
						cin >> researchScore;
						cout << endl;


					cout << "Please enter the student's country" << endl;
					cin >> Country;


						cout << "Please enter the student's Toefl reading score" << endl;
						cin >> toeflReading;
						cout << endl;





						cout << "Please enter the student's Toefl listening score" << endl;
						cin >> toeflListening;
						cout << endl;




						cout << "Please enter the student's Toefl speaking score" << endl;
						cin >> toeflSpeaking;
						cout << endl;




						cout << "Please enter the student's Toefl writing score" << endl;
						cin >> toeflWriting;
						cout << endl;






						if (cgpa < 0 || cgpa>4.33) {
							cerr << "Invalid CGPA. CGPA must be between 0 and 4.33\nThe student will not be considered\n";
						}
						else if (researchScore < 0 || researchScore>100) {
							cerr << "Invalid research score. Research scores must be between 0 and 100\nThe student will not be considered\n";
						}
						else if (toeflListening < 20 || toeflListening>30) {
							cerr << "Invalid Toefl listening score. Listening scores must be between 20 and 30\nThe student will not be considered\n";
						}

						else if (toeflReading < 20 || toeflReading>30) {
							cerr << "Invalid Toefl reading score. Reading scores must be between 20 and 30\nThe student will not be considered\n";
						}
						else if (toeflSpeaking < 20 || toeflSpeaking>30) {
							cerr << "Invalid Toefl speaking score. Speaking scores must be between 20 and 30\nThe student will not be considered\n";
						}
						else if (toeflWriting < 20 || toeflWriting>30) {
							cerr << "Invalid Toefl writing score. Writing scores must be between 20 and 30 \nThe student will not be considered\n";
						}
						else if (toeflListening + toeflReading + toeflSpeaking + toeflWriting < 93) {
							cerr << "Error: The student Total toefl score does not meet the requrement of being higher than 93\nThe student will not be considered\n ";
						}
						else {
							studentPtr inInt = new InternationalStudent(firstName, lastName, cgpa, researchScore, stu_num + 20200000, Country, toeflReading, toeflListening, toeflSpeaking, toeflWriting);
							insert((search(intHead, inInt, sortInt)), intHead, intTail, inInt, sortInt);

							studentPtr tempint = new InternationalStudent;
							tempint = intHead;
							while (tempint != nullptr)
							{
								cout << *tempint;
								tempint = tempint->get_link();
							}
							delete tempint;
						}

				}
				stu_num++;
				cout << endl;
				cout << "Would you like to add another student?" << endl;
				cout << "press 'y' to add again:  ";
				cin >> addAnother;

				if (addAnother != 'y' && addAnother != 'Y')
				{
					break;
				}
				else
				{
					cout << endl;

					continue;
				}
			}
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		}
		else
		{
		//////////////////////////////////////////////////////////////////////////DELETE STUDENTS////////////////////////////////////////////////////////
		while (deleteAnother == 'y' || deleteAnother == 'Y')
		{
			deleteAnother = 'n';
			string firstname, lastname;
			int delChoice = 0;
			cout << "Would you like to delete one student or all top and bottom students?" << endl;
			cout << "[1] One Student" << endl;
			cout << "[2] The current head and tail" << endl;
			cin >> delChoice;

			if (delChoice > 2 || delChoice < 1)
			{
				cerr << "ERROR: Please select a proper option" << endl;
				delChoice = 'p';


				continue;
			}

			if (delChoice == 1)
			{
				cout << "Please enter the first name of the student to be deleted" << endl;
				cin >> firstname;
				cout << endl;

				cout << "Please enter the last name of the student to be deleted" << endl;
				cin >> lastname;
				cout << endl;

				studentPtr temp1 = domHead;
				studentPtr temp2 = intHead;



				while (temp1 != nullptr)
				{
					char confirmation = '\0';
					temp1 = deleteSearch(domHead, temp1, sortDom, firstname, lastname);
					if (temp1 == nullptr)
					{
						break;
					}
					/*
					cout << "Do you want to delete this student?" << endl;
					cout << *temp1;
					cout << "Choice (y/n): ";
					cin >> confirmation;
					cout << endl;
					*/
					//if (confirmation == 'y' || confirmation == 'Y') {
						deleteStudent(domHead, domTail, temp1, sortDom);
					//}

				}
				while (temp2 != nullptr)
				{
					char confirmation = '\0';
					temp2 = deleteSearch(intHead, temp2, sortDom, firstname, lastname);
					if (temp2 == nullptr)
					{
						break;
					}

					/*
					cout << "Do you want to delete this student?" << endl;
					cout << *temp1;
					cout << "Choice (y/n): ";
					cin >> confirmation;
					cout << endl;
					*/
					//if (confirmation == 'y' || confirmation == 'Y') {
						deleteStudent(domHead, domTail, temp2, sortDom);
					//}
				}

				studentPtr tempint;
				studentPtr tempdom;
				tempdom = domHead;
				while (tempdom != nullptr)
				{
					cout << *tempdom;
					tempdom = tempdom->get_link();
				}

				cout << endl;

				tempint = intHead;
				while (tempint != nullptr)
				{
					cout << *tempint;
					tempint = tempint->get_link();
				}
			}
			else
			{
				studentPtr temp = domHead;
				studentPtr temp2 = intHead;
				char heta = 'b';
				deleteStudent(domHead, domTail, temp, heta);
				deleteStudent(intHead, intTail, temp2, heta);


				studentPtr tempint;
				studentPtr tempdom;
				tempdom = domHead;
				while (tempdom != nullptr)
				{
					cout << *tempdom;
					tempdom = tempdom->get_link();
				}
				tempint = intHead;
				while (tempint != nullptr)
				{
					cout << *tempint;
					tempint = tempint->get_link();
				}
			}

			cout << endl;
			cout << "Would you like to delete another student?" << endl;
			cout << "press 'y' to delete again:  ";
			cin >> deleteAnother;

			if (deleteAnother != 'y' && deleteAnother != 'Y')
			{
				break;
			}
			else
			{
				cout << endl;

				continue;
			}

		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		}


		cout << endl;
		cout << "Would you like to go back to the homepage?" << endl;
		cout << "press 'y' to sort again:  ";
		cin >> gotoHome;

		if (gotoHome != 'y' && gotoHome != 'Y')
		{
			break;
		}
		else
		{
			cout << endl;

			continue;
		}




	}

	merge(domHead, intHead, head, tail);


	studentPtr temp = new Student;
	temp = head;

	while (temp != nullptr) {
		cout << *temp;

		if (temp->get_link() == nullptr) {
			tail = temp;
		}
		temp = temp->get_link();

	}
	delete temp;
	cout << endl;


	homeChoice = 0;
	gotoHome = 'y';

	// INTERFACE
	while (gotoHome == 'y' || gotoHome == 'Y') //This while loop is for asking the user if they want to come back to homepage
	{
		gotoHome = 'n';
		char searchAgain = 'y';
		char addAnother = 'y';
		char deleteAnother = 'y';
		char searchType = 'p';
		char studType = 'p';
		int idChoice = 0;

		string firstname = "";
		string lastname = "";


		cout << "Welcome to SFU! What would you like to do today?" << endl;

		cout << "[1] Search For A Student" << endl;
		cout << "[2] Add A Student" << endl;
		cout << "[3] Delete A Student" << endl;
		cout << "[4] Filter Merged List" << endl;
		cout << "[5] Exit Program" << endl;

		cout << "Choice: ";
		cin >> homeChoice;
		cout << endl;

		if (homeChoice > 5 || homeChoice <= 0)
		{
			cerr << "ERROR: Please select a proper option" << endl;
			homeChoice = 0;


			continue;
		}

		if (homeChoice == 5)
		{
			break;
		}
		else if (homeChoice == 4)
		{

			int cgpa = -1;
			int researchScore = -1;

			while (cgpa < 0 || cgpa >4.33) {


				cout << "Enter the CGPA threshold for SFU admission" << endl;
				cin >> cgpa;
				if ((cgpa < 0 || cgpa >4.33)) {
					cerr << "Not a valid CGPA\nPlease Enter A Value from 0 to 4.33\n";
				}

			}

			while (researchScore < 0 || researchScore > 100) {


				cout << "Enter the research score threshold for SFU admission" << endl;
				cin >> researchScore;
				if (researchScore < 0 || researchScore > 100) {
					cerr << "Not a valid Research Score\nPlease Enter A Value from 0 to 100\n";
				}
			}

			////////////////////////////////////////     Code For Filtering           /////////////////////////////////////////////
			threshold(head, cgpa, researchScore );

		}

		else if (homeChoice == 1)
		{
			//////////////////////////////////////////////////////////////////////////SEARCHING////////////////////////////////////////////////////////
			while (searchAgain == 'y' || searchAgain == 'Y')
			{
				idChoice = 'p';
				float cgpaChoice = 0;
				firstname = "";
				string lastname = "";
				cout << "What would you like to search?" << endl;
				cout << "[N] Full Name " << endl;
				cout << "[C] CGPA" << endl << "[R] Research Score " << endl;
				cout << "[I] Student ID" << endl;

				cout << "Choice: ";
				cin >> searchType;
				cout << endl;

				if (searchType != 'n' && searchType != 'N' && searchType != 'c' && searchType != 'C' && searchType != 'r' && searchType != 'R' && searchType != 'I' && searchType != 'i' || cin.peek() != '\n')
				{
					cerr << "ERROR: Please select a proper searching category" << endl;
					searchType = 'p';


					continue;
				}
				// SEARCH FUNCTIONS

				if (searchType == 'I' || searchType == 'i')
				{
					cout << "Please enter the ID you would like to find" << endl;
					cin >> idChoice;
					searchID(head, nullptr, idChoice);
				}
				else if (searchType == 'c' || searchType == 'C')
				{
					cout << "Please enter the CGPA you would like to find" << endl;
					cin >> cgpaChoice;
					searchCGPA(head, nullptr, cgpaChoice);
				}
				else if (searchType == 'r' || searchType == 'R')
				{
					cout << "Please enter the research score you would like to find" << endl;
					cin >> idChoice;
					searchReScore(head, nullptr, idChoice);
				}
				else if (searchType == 'n' || searchType == 'N')
				{
					cout << "Please enter the first name you would like to find" << endl;
					cin >> firstname;
					cout << endl;
					cout << "Please enter the last name you would like to find" << endl;
					cin >> lastname;
					cout << endl;

					searchName(head, nullptr, firstname, lastname);

				}

				cout << endl;
				cout << "Would you like to search again?" << endl;
				cout << "press 'y' to search again:  ";
				cin >> searchAgain;

				if (searchAgain != 'y' && searchAgain != 'Y')
				{
					break;
				}
				else
				{
					cout << endl;

					continue;
				}

			}
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		}
		else if (homeChoice == 2)
		{
			//////////////////////////////////////////////////////////////////////////INSERT NEW STUDENTS////////////////////////////////////////////////////////
			while (addAnother == 'y' || addAnother == 'Y')
			{
				cout << "Pick your student type" << endl;
				cout << "[D] Domestic" << endl;
				cout << "[I] International" << endl;

				cout << "Choice: ";
				cin >> studType;
				cout << endl;

				if (studType != 'd' && studType != 'D' && studType != 'i' && studType != 'I' || cin.peek() != '\n')
				{
					cerr << "ERROR: Please select a proper student type" << endl;
					studType = 'p';


					continue;
				}

				if (studType == 'd' || studType == 'D')
				{
					string firstName, lastName, province = "";
					float cgpa = -1;
					int researchScore = -1;


					cout << "Please enter the student's first name" << endl;
					cin >> firstName;
					cout << endl;

					cout << "Please enter the student's last name" << endl;
					cin >> lastName;
					cout << endl;


						cout << "Please enter the student's CGPA" << endl;
						cin >> cgpa;
						cout << endl;




						cout << "Please enter the student's research score" << endl;
						cin >> researchScore;
						cout << endl;




						cout << "Please enter the student's province" << endl;
						cin >> province;



						if (cgpa < 0 || cgpa>4.33) {
							cerr << "Invalid CGPA. CGPA must be between 0 and 4.33\nThe student will not be considered\n";
						}
						else if (researchScore < 0 || researchScore>100) {
							cerr << "Invalid research score. Research scores must be between 0 and 100\nThe student will not be considered\n";
						}
						else if (province != "BC" && province != "AB" & province != "ON" & province != "MB" && province != "NB" && province != "NL" && province != "YT" && province != "SK" && province != "NU" && province != "NS" && province != "QC" && province != "NT" && province != "NU" && province != "PE") {
							cerr << "Invalid Province. \nPlease make sure the provinces are in their proper acronyms \nChoices:BC, AB, ON, MB, NB, NL, YT, SK, NU, NS, QC, NT, PE\nThe student will not be considered\n";
						}
						else {
							studentPtr inDom = new DomesticStudent(firstName, lastName, cgpa, researchScore, stu_num + 20200000, province);
							insert((search(head, inDom, sortDom)), head, tail, inDom, sortDom);



							studentPtr tempdom = new DomesticStudent;
							tempdom = head;
							while (tempdom != nullptr)
							{
								cout << *tempdom;
								tempdom = tempdom->get_link();
							}
						}


				}
				else
				{
					string firstName, lastName, Country = "";
					float cgpa = -1;
					int researchScore = -1;
					int toeflReading = -1;
					int toeflListening = -1;
					int toeflSpeaking = -1;
					int toeflWriting = -1;


					cout << "Please enter the student's first name" << endl;
					cin >> firstName;
					cout << endl;

					cout << "Please enter the student's last name" << endl;
					cin >> lastName;
					cout << endl;


						cout << "Please enter the student's CGPA" << endl;
						cin >> cgpa;
						cout << endl;




						cout << "Please enter the student's research score" << endl;
						cin >> researchScore;
						cout << endl;


					cout << "Please enter the student's country" << endl;
					cin >> Country;


						cout << "Please enter the student's Toefl reading score" << endl;
						cin >> toeflReading;
						cout << endl;





						cout << "Please enter the student's Toefl listening score" << endl;
						cin >> toeflListening;
						cout << endl;




						cout << "Please enter the student's Toefl speaking score" << endl;
						cin >> toeflSpeaking;
						cout << endl;




						cout << "Please enter the student's Toefl writing score" << endl;
						cin >> toeflWriting;
						cout << endl;




					if (cgpa < 0 || cgpa>4.33) {
						cerr << "Invalid CGPA. CGPA must be between 0 and 4.33\nThe student will not be considered\n";
					}
					else if (researchScore < 0 || researchScore>100) {
						cerr << "Invalid research score. Research scores must be between 0 and 100\nThe student will not be considered\n";
					}
					else if (toeflListening < 20 || toeflListening>30) {
						cerr << "Invalid Toefl listening score. Listening scores must be between 20 and 30\nThe student will not be considered\n";
					}

					else if (toeflReading < 20 || toeflReading>30) {
						cerr << "Invalid Toefl reading score. Reading scores must be between 20 and 30\nThe student will not be considered\n";
					}
					else if (toeflSpeaking < 20 || toeflSpeaking>30) {
						cerr << "Invalid Toefl speaking score. Speaking scores must be between 20 and 30\nThe student will not be considered\n";
					}
					else if (toeflWriting < 20 || toeflWriting>30) {
						cerr << "Invalid Toefl writing score. Writing scores must be between 20 and 30 \nThe student will not be considered\n";
					}
					else if (toeflListening+ toeflReading + toeflSpeaking + toeflWriting < 93) {
						cerr << "Error: The student Total toefl score does not meet the requrement of being higher than 93\nThe student will not be considered\n ";
					}
					else {
						studentPtr inInt = new InternationalStudent(firstName, lastName, cgpa, researchScore, stu_num + 20200000, Country, toeflReading, toeflListening, toeflSpeaking, toeflWriting);
						insert((search(head, inInt, sortInt)), head, tail, inInt, sortInt);

						studentPtr tempint = new InternationalStudent;
						tempint = head;
						while (tempint != nullptr)
						{
							cout << *tempint;
							tempint = tempint->get_link();
						}
						delete tempint;
					}

				}

				stu_num++;
				cout << endl;
				cout << "Would you like to add another student?" << endl;
				cout << "press 'y' to add again:  ";
				cin >> addAnother;

				if (addAnother != 'y' && addAnother != 'Y')
				{
					break;
				}
				else
				{
					cout << endl;

					continue;
				}
			}
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		}
		else
		{
		//////////////////////////////////////////////////////////////////////////DELETE STUDENTS////////////////////////////////////////////////////////
		while (deleteAnother == 'y' || deleteAnother == 'Y')
		{
			deleteAnother = 'n';
			string firstname, lastname;
			int delChoice = 0;
			cout << "Would you like to delete one student or all top and bottom students?" << endl;
			cout << "[1] One Student" << endl;
			cout << "[2] The current head and tail" << endl;
			cin >> delChoice;

			if (delChoice > 2 || delChoice < 1)
			{
				cerr << "ERROR: Please select a proper option" << endl;
				delChoice = 'p';


				continue;
			}

			if (delChoice == 1)
			{
				cout << "Please enter the first name of the student to be deleted" << endl;
				cin >> firstname;
				cout << endl;

				cout << "Please enter the last name of the student to be deleted" << endl;
				cin >> lastname;
				cout << endl;

				studentPtr temp1 = head;




				while (temp1 != nullptr)
				{
					char confirmation = '\0';
					temp1 = deleteSearch(head, temp1, sortDom, firstname, lastname);
					if (temp1 == nullptr)
					{
						break;
					}
					/*
					cout << "Do you want to delete this student?" << endl;
					cout << *temp1;
					cout << "Choice (y/n): ";
					cin >> confirmation;
					cout << endl;
					*/
					//if (confirmation == 'y' || confirmation == 'Y') {
						deleteStudent(head, tail, temp1, sortDom);
					//}

				}


				studentPtr tempdom;
				tempdom = head;
				while (tempdom != nullptr)
				{
					cout << *tempdom;
					tempdom = tempdom->get_link();
				}
				delete tempdom;

				cout << endl;


			}
			else
			{
				studentPtr temp = head;

				char heta = 'b';
				deleteStudent(head, tail, temp, heta);




				studentPtr tempdom;
				tempdom = head;
				while (tempdom != nullptr)
				{
					cout << *tempdom;
					tempdom = tempdom->get_link();
				}

			}

			cout << endl;
			cout << "Would you like to delete another student?" << endl;
			cout << "press 'y' to delete again:  ";
			cin >> deleteAnother;

			if (deleteAnother != 'y' && deleteAnother != 'Y')
			{
				break;
			}
			else
			{
				cout << endl;

				continue;
			}

		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		}


		cout << endl;
		cout << "Would you like to go back to the homepage?" << endl;
		cout << "press 'y' to sort again:  ";
		cin >> gotoHome;

		if (gotoHome != 'y' && gotoHome != 'Y')
		{
			break;
		}
		else
		{
			cout << endl;

			continue;
		}


	}

	while(head != nullptr) // deleting all nodes before exiting the program
	{
		studentPtr temp = head;
		head = head->get_link();

		temp->set_link(nullptr);
		delete temp;
	}


	head = nullptr;
	tail = nullptr;
	intHead = nullptr;
	domHead = nullptr;
	intTail = nullptr;
	domTail = nullptr;

	return 0;
}
