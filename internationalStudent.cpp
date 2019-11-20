#include "internationalStudent.hpp"
#include "toeflScore.hpp"
//INTERNATIONAL STUDENT DEFINITION

//International student constructor. Member variables of parent class Student, like the first and last name, are initialzed using the set
//functions, as the parent constructor cant be called in the function body. The member variable unique to international student, the country, is
//also initialized. In addition, the individual toefl score elements are initialized using the TOEFL variable, of class ToeflScore, and using
//its set member functiion
InternationalStudent::InternationalStudent(string FN, string LN, float gradept, int research, int ID, string homecountry, int read, int listen, int speak, int write)
{
	set_firstname(FN); //FN = firstname, LN = lastname, gradept = cgpa,research = researchscore
	set_lastname(LN);
	set_cgpa(gradept);
	set_researchscore(research);
	set_appID(ID);
	errorcheck();//calling error checking function to ensure valid values
	TOEFL.set_reading(read);//TOEFL, which is a private member variable of InternationalStudent of type ToeflScore, uses its
   //set member function to initialize the individual scores, and the total. The reason the constructor of ToeflScore is not 
   //used is because it creates another object, an anonymous one.
	TOEFL.set_listening(listen);
	TOEFL.set_speaking(speak);
	TOEFL.set_writing(write);
	TOEFL.set_total(read, listen, speak, write);
	country = homecountry;//initializing the member function unique to international student
}

//Default student constructor. The set functions for member varibales of parent class Student are called
//and TOEFL member functions are used to set the individual scores to 0. Member varibale country, unique to
//international student is initialized too
InternationalStudent::InternationalStudent()
{
	set_firstname("INAME");
	set_lastname("ISURNAME");
	set_cgpa(0.00);
	set_researchscore(0);
	set_appID(20200000);
	TOEFL.set_reading(0);
	TOEFL.set_listening(0);
	TOEFL.set_speaking(0);
	TOEFL.set_writing(0);
	country = "ICOUNTRY";
}

//mutator/set function for the member varibale country, unique to international student. No error checking for strings.
void InternationalStudent::set_country(string home)
{
	country = home;
}

//accessor/get function for the member varibale country
string InternationalStudent::get_country() const
{
	return(country);
}

//mutator/set function for setting the value of the reading score of the overall toeflscore. This is 
//acheived by using the set_reading function of the TOEFL object. No error checking in this function since
//it is done in the member function of Toefl, set_reading.
void InternationalStudent::set_Tread(int read)
{
	TOEFL.set_reading(read);
}

//accessor/get function for getting the value of the reading score of the toefl score. Returned is the 
//value that is returned when the get_reading function of the class toeflscore is called, for object TOEFL.
int InternationalStudent::get_Tread() const
{
	return(TOEFL.get_reading());
}

//mutator/set function for listening score, using TOEFL.set_listening so that each international student
//object has acccess to the indiviudal scores
void InternationalStudent::set_Tlisten(int listen)
{
	TOEFL.set_listening(listen);
}

//accessor/get function to return the value of the listening score, using the get_listening function
//of the TOEFL class
int InternationalStudent::get_Tlisten() const
{
	return(TOEFL.get_listening());
}

//mutator/set function for the speaking score of the overall Toefl score for that student
void InternationalStudent::set_Tspeak(int speak)
{
	TOEFL.set_speaking(speak);
}

//accessor/get function for the speaking score, calling the get_speaking function of class ToeflScore
int InternationalStudent::get_Tspeak() const
{
	return(TOEFL.get_speaking());
}

//mutator/set function for the writing score, calling the set_writing function of obejct TOEFL
void InternationalStudent::set_Twrite(int write)
{
	TOEFL.set_writing(write);
}

//accessor/get function of writing score, so that each international student object can access the individual scores
int InternationalStudent::get_Twrite() const
{
	return(TOEFL.get_writing());
}

//mutator/set function of total toefl score, which calls the set_total member function of object toefl, which adds the parameters
//passed (individual scores) to get the total
void InternationalStudent::set_Ttotal(int read, int write, int listen, int speak)
{
	TOEFL.set_total(read, write, listen, speak);
}

//accessor/get function for the total score, which returns the returned value from the TOEFL objects function, get_total 
int InternationalStudent::get_Ttotal() const
{
	return(TOEFL.get_total());
}

//comparing the countries of two international student objects to eventually sort them alphabetically
//sort based on ASCII values such that if stu1 has a lower ASCII value (closer to A) then return 1. Return 0 if theyre equal, and -1 if stu2 preceeds stu1 in country alphabetical sorting
int compareCountry(const InternationalStudent &stu1, const InternationalStudent &stu2)
{
	int i = 0;
	while (stu1.get_country()[i] != '\0' && stu2.get_country()[i] != '\0')
	{
		//greater ASCII values means closer to Z
		if (stu1.get_country()[i] < stu2.get_country()[i])
		{
			return(1);//return 1 as stu1 country preceeds alphabetically
		}
		if (stu1.get_country()[i] > stu2.get_country()[i])
		{
			return(-1);//return -1 as stu2 country preceeds alphabetically
		}
		i++;
	}
	//check that if they are the same value, but one is shorter, return 1 if stu1 is shorter, -1 if stu2 is
	//stu1 is shorter
	if (stu1.get_country()[i] == '\0' && stu2.get_country()[i] != '\0')
	{
		return(1);
	}
	//stu2 is shorter
	if (stu1.get_country()[i] != '\0' && stu2.get_country()[i] == '\0')
	{
		return(-1);
	}
	return(0);
}


//comparing the toefl scores of two international student objects. return 1 if stu1 is larger, 0 if equal, -1 if stu2 is greater
int compareToeflScore(const InternationalStudent &stu1, const InternationalStudent &stu2)
{
	if (stu1.get_Ttotal() > stu2.get_Ttotal())
	{
		return(1);//1 if stu1 is greater
	}
	if (stu1.get_Ttotal() == stu2.get_Ttotal())
	{
		return(0);//0 if theyre equal
	}
	if (stu1.get_Ttotal() < stu2.get_Ttotal())
	{
		return(-1);//-1 if stu2 is greater
	}
}

//checking to see if the given international students scores meet minimum requirements for entry
bool InternationalStudent::checkTOEFLreq(int read, int write, int speak, int listen)
{
	int tot = read + write + speak + listen; //creating the total value
	if (read < 20 || write < 20 || speak < 20 || listen < 20)//all must be atleast 20, individually
		return false;
	else if (tot < 93)//must add to atleast 93
		return false;
	else return true; //true if meets all requirments
}

//overloading the ouput operator for easy use of << in main. Pass outputstream and object to output
ostream& operator <<(ostream& outs, const InternationalStudent& stu)
{
	outs << setw(20) << left << stu.get_appID() //use iomanip library to incorporate setw for spacing outputs
		<< setw(20) << left << stu.get_firstname()
		<< setw(20) << left << stu.get_lastname()
		<< setw(20) << left << stu.get_researchscore() //research score first since it has precedence over cgpa
		<< setw(20) << left << stu.get_cgpa()
		<< setw(20) << left << stu.get_country()
		<< setw(10) << left << stu.get_Ttotal()
		<< setw(10) << left << stu.get_Tread()
		<< setw(10) << left << stu.get_Twrite()
		<< setw(10) << left << stu.get_Tlisten()
		<< setw(10) << left << stu.get_Tspeak();
	return(outs);//return the output stream to be printed
}

//overloading equals operator to allow for easy swapping of objects or assigning to one another
void InternationalStudent::operator =(const InternationalStudent& right_side)
{
	//the set functions are setting the values of the object on the LEFT side of the equals sign implicitly
	set_firstname(right_side.get_firstname());
	set_lastname(right_side.get_lastname());
	set_researchscore(right_side.get_researchscore());
	set_cgpa(right_side.get_cgpa());
	set_appID(right_side.get_appID());
	set_Twrite(right_side.get_Twrite());
	set_Tread(right_side.get_Tread());
	set_Tlisten(right_side.get_Tlisten());
	set_Tspeak(right_side.get_Tspeak());
	set_Ttotal(right_side.get_Tspeak(), right_side.get_Tlisten(), right_side.get_Twrite(), right_side.get_Tread());//pass all scores to set total
	set_country(right_side.get_country());
}

//copy constructor to copy the member variables of the international student object Istu to avoid pointing to the same memory, then deleting one pointer and losing another
InternationalStudent::InternationalStudent(const InternationalStudent& Istu)
{
	InternationalStudent Intobj;//creating an international student object to hold the copied values
	Intobj.set_firstname(Istu.get_firstname());//copy each element using the set function for Intobj and get fucntions for the passed object
	Intobj.set_lastname(Istu.get_lastname());
	Intobj.set_researchscore(Istu.get_researchscore());
	Intobj.set_cgpa(Istu.get_cgpa());
	Intobj.set_appID(Istu.get_appID());
	Intobj.set_Twrite(Istu.get_Twrite());
	Intobj.set_Tread(Istu.get_Tread());
	Intobj.set_Tlisten(Istu.get_Tlisten());
	Intobj.set_Tspeak(Istu.get_Tspeak());
	Intobj.set_Ttotal(Istu.get_Tread(), Istu.get_Twrite(), Istu.get_Tlisten(), Istu.get_Tspeak());
	Intobj.set_country(Istu.get_country());
}

//default destuctor to ensure dynamic member variables are destroyed properly when passed by value to member functions
InternationalStudent::~InternationalStudent()
{
	// intentionally empty
}

bool operator == (InternationalStudent &student1, InternationalStudent &student2) {

	//used to compare values of two domestic students
	if (student1.get_firstname() == student2.get_firstname() &&
		student1.get_lastname() == student2.get_lastname() &&
		student1.get_country() == student2.get_country() &&
		student1.get_cgpa() == student2.get_cgpa() &&
		student1.get_researchscore() == student2.get_researchscore())
	{
		return true;
	}
	return false;
}