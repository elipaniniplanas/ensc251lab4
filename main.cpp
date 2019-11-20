//main.cpp, put your driver code here, 
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include "student.hpp"

int main() 
{
	string line;
	ifstream domesticFile("domestic-stu.txt");
	if (!domesticFile.is_open()) {
		cout << "Unable to open file domestic-stu.txt" << endl;
		return -1;
	}
	
	cout<<"Domestic students: "<<endl;
	//Read the first line of domestic-stu.txt, which specifies
	//the file format. And then print it out to the screen
	getline(domesticFile, line);
	cout << "File format: " << line << endl;

	int stu_count = 1;
	int i = 0;
	int dnum = 100;
	NodePtr d_h = NULL;
	while (getline(domesticFile, line)) 
	{
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
		
		D_StudentPtr s = new DomesticStudent;
		s->setFirst(firstName);
		s->setLast(lastName);
		s->setCGPA(cgpa);
		s->setResearch(researchScore);
		s->setProvince(province);
		s->setApplication(20200000 + stu_count - 1);

		insert(d_h, s);

		stu_count++;
		i++;
	}

	//close your file
	domesticFile.close();

	print_link(d_h);
	
	cout<<"\n\n\n";

	string line2;
	ifstream internationalFile("international-stu.txt");
	if (!internationalFile.is_open()) 
	{
		cout << "Unable to open file domestic-stu.txt" << endl;
		return -1;
	}
	
	cout<<"International students:"<<endl;
	getline(internationalFile, line2);
	cout << "File format: " << line2 << endl;

	i = 0;
	int inum = 100;
	NodePtr i_h = NULL;
	while (getline(internationalFile, line2)) 
	{
		istringstream ss(line2);

		string firstName, lastName, country, s_cgpa, s_researchScore, s_read, s_listen, s_speak, s_write;
		float cgpa;
		int researchScore;
		int read, listen, speak, write;
		ToeflScore toefl;

		getline(ss, firstName, ',');

		getline(ss, lastName, ',');

		getline(ss, country, ',');

		getline(ss, s_cgpa, ',');
		cgpa = atof(s_cgpa.c_str());

		getline(ss, s_researchScore, ',');
		researchScore = atoi(s_researchScore.c_str());

		getline(ss, s_read, ',');
		read = atoi(s_read.c_str());

		getline(ss, s_listen, ',');
		listen = atoi(s_listen.c_str());

		getline(ss, s_speak, ',');
		speak = atoi(s_speak.c_str());

		getline(ss, s_write, ',');
		write = atoi(s_write.c_str());

		toefl.setReading(read);
		toefl.setListening(listen);
		toefl.setSpeaking(speak);
		toefl.setWriting(write);
		toefl.setTotal();

		I_StudentPtr s = new InternationalStudent;
		s->setFirst(firstName);
		s->setLast(lastName);
		s->setCGPA(cgpa);
		s->setResearch(researchScore);
		s->setCountry(country);
		s->setToefl(toefl);
		s->setApplication(20200000 + stu_count - 1);

		insert(i_h, s);
		
		stu_count++;
		i++;
	}

	//close your file
	internationalFile.close();

	print_link(i_h);
	cout << "\n\n\n";

	sortAll(d_h, i_h);
	print_link(d_h);
	cout << "\n\n\n";

	searchCGPA(d_h);
	cout << "\n\n\n";

	searchResearch(d_h);
	cout << "\n\n\n";

	searchID(d_h);
	cout << "\n\n\n";

	searchName(d_h);
	cout << "\n\n\n";

	insertDomestic(d_h);
	print_link(d_h);
	cout << "\n\n\n";

	insertInternationl(d_h);
	print_link(d_h);
	cout << "\n\n\n";

	deleteExistNode(d_h);
	print_link(d_h);
	cout << "\n\n\n";

	remove_front_tail(d_h);
	print_link(d_h);
	cout << "\n\n\n";

	searchMerged(d_h);

	cout << endl;
	
	return 0;
}
