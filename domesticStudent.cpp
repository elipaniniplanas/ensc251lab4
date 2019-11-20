#include "domesticStudent.hpp"
//DOMESTIC STUDENT DEFINTION

//Domestic student constructor, which takes FN(firstname), LN (lastname), gradept(cgpa), research (researchscore)
//Id(application number), prov(province),and uses them to initialize member variables. Set functions are used to
//initialize variables that are in the parent class Student, where we alternitivley could have called the
//Student constructor in the initialization section. Set is used since the parent constructor cant be called in the
//function body
DomesticStudent::DomesticStudent(string FN, string LN, float gradept, int research, int ID, string prov)
{
	set_firstname(FN);//using set since the constructor for student cant be calld in the body
	set_lastname(LN);
	set_cgpa(gradept);
	set_researchscore(research);
	set_appID(ID);
	province = prov;
	//province error check

	if (province != "BC" && province != "AB" && province != "NS" &&  province != "NU" &&  province != "ON" &&  province != "PE" &&  province != "QC" &&  province != "SK" &&  province != "YT" && province != "MB" && province != "NB" && province != "NL" && province != "NT")
	{
		cout << "Error: Invalid province. Exiting Program.";
		exit(-1);
	}
	errorcheck();//calling the error check function to ensure the initialized values are valid. The error checking function
   //is in parent class Student
}

//Default domestic student constructor, where the set functions are used to initialize the variables that are a part of
//parent class Student, instead of calling the Student constructor in the initalization section.
DomesticStudent::DomesticStudent()
{
	set_firstname("DNAME");
	set_lastname("DSURNAME");
	set_cgpa(0.00);
	set_researchscore(0);
	set_appID(20200000);
	province = "DPROVINCE";
}

//mutator/set function for the varibale province of domestic student, with errror checking included
void DomesticStudent::set_province(string provi)
{
	province = provi;
	//checking province entered is valid pair of letters
	/*
	if (province != "BC" && province != "AB" && province != "NS" && province != "NU" && province != "ON" && province != "PE" && province != "QC" && province != "SK" && province != "YT" &&  province != "MB" &&  province != "NB" &&  province != "NL" && province != "NT")
	{
		cout << "Error: Invalid province. Exiting Program.";
		exit(-1);
	}
	*/
}

//accessor/get function for the province variable
string DomesticStudent::get_province() const
{
	return(province);
}


//compare province strings so that a while loop increments thru the array of characters and if one is lesser than the other, ie has lower ASCII value, then it preceeds alphabetically
int compareProvince(const DomesticStudent &stu1, const DomesticStudent &stu2)
{
	int i = 0;
	while (stu1.get_province()[i] != '\0' && stu2.get_province()[i] != '\0')
	{
		//greater ASCII number means closer to z
		if (stu1.get_province()[i] < stu2.get_province()[i])
		{

			return(1);//return 1 if stu1 preceeds alphabetically
		}
		if (stu1.get_province()[i] > stu2.get_province()[i])
		{
			return(-1);// return -1 if stu2 preceeds
		}
		i++;
	}
	//check if the strings are same value but have different lengths. In that case print shorter one with alphabetical precedence
	//stu2 is longer
	if (stu1.get_province()[i] == '\0' && stu2.get_province()[i] != '\0')
	{
		return(1);
	}
	//stu1 is longer
	if (stu1.get_province()[i] != '\0' && stu2.get_province()[i] == '\0')
	{
		return(-1);
	}
	return(0);
}

//overloading the output operator to print the data of domestic students
ostream& operator <<(ostream& outs, const DomesticStudent& stu)
{
	outs << setw(20) << left << stu.get_appID() //using setw to format for consistent spacing
		<< setw(20) << left << stu.get_firstname()
		<< setw(20) << left << stu.get_lastname()
		<< setw(20) << left << stu.get_researchscore() //research score before cgpa since it has precedence in sorting
		<< setw(20) << left << stu.get_cgpa()
		<< setw(20) << left << stu.get_province() << endl;
	return(outs);//return the output stream, now with all the data written to it
}

//overloading equals operator to allow for simple swapping of objects
void DomesticStudent::operator =(const DomesticStudent& right_side)
{
	//no dot operator for set since the object on the left side of the equals is being changed by default
	//set the left side values to that of the rigt side
	set_firstname(right_side.get_firstname());
	set_lastname(right_side.get_lastname());
	set_researchscore(right_side.get_researchscore());
	set_cgpa(right_side.get_cgpa());
	set_appID(right_side.get_appID());
	set_province(right_side.get_province());
}

//copy constructor where the object passed has its values copied to a new domestic student object
DomesticStudent::DomesticStudent(const DomesticStudent& Dstu)
{
	DomesticStudent domobj;//object to hold the values of Dstu
	domobj.set_firstname(Dstu.get_firstname());
	domobj.set_lastname(Dstu.get_lastname());
	domobj.set_researchscore(Dstu.get_researchscore());
	domobj.set_cgpa(Dstu.get_cgpa());
	domobj.set_appID(Dstu.get_appID());
	domobj.set_province(Dstu.get_province());
}

//default destructor to allow for deleting memort of dynamic member variables
DomesticStudent::~DomesticStudent()
{
	//internationally empty
}

bool operator == (DomesticStudent &student1, DomesticStudent &student2) {

//used to compare values of two domestic students
	if (student1.get_firstname() == student2.get_firstname() &&
		student1.get_lastname() == student2.get_lastname() &&
		student1.get_province() == student2.get_province() &&
		student1.get_cgpa() == student2.get_cgpa() &&
		student1.get_researchscore() == student2.get_researchscore())
	{
		return true;
	}
	return false;
}