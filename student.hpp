//header file student.hpp to declare your classes
using namespace std; //use namespace std
#include <string> //you will have to use string in C++
#include <iostream>

class ToeflScore
{
private:
	int reading;
	int listening;
	int speaking;
	int writing;
	int total_score;
public:
	ToeflScore();
	ToeflScore(const int&, const int&, const int&, const int&);
	int getReading() const;
	int getListening() const;
	int getSpeaking() const;
	int getWriting() const;
	int getTotal() const;
	void set(const int&, const int&, const int&, const int&);
	void setReading(const int& read);
	void setListening(const int& listen);
	void setSpeaking(const int& speak);
	void setWriting(const int& write);
	void setTotal();
	ToeflScore& operator = (const ToeflScore& f);
};

//the class of student is the parent class
class Student
{
public:
	//getter
	virtual string getFirst() const = 0;
	virtual string getLast() const = 0;
	virtual float getCGPA() const = 0;
	virtual int getResearch() const = 0;
	virtual int getApplication() const = 0;
	virtual string getProvince() const = 0;
	virtual string getCountry() const = 0;
	virtual ToeflScore getToefl() const = 0;
	virtual void print() const = 0;
        //friend function
	friend int compareCGPA(const Student* a, const Student* b);
	friend int compareResearchScore(const Student* a, const Student* b);
	friend int compareFirstName(const Student* a, const Student* b);
	friend int compareLastName(const Student* a, const Student* b);
	friend int compareCountry(const Student* a, const Student* b);
	friend int compareProvince(const Student* a, const Student* b);
	friend int compareCGPA(const Student& a, const Student& b);
	friend int compareResearchScore(const Student& a, const Student& b);
	friend int compareFirstName(const Student& a, const Student& b);
	friend int compareLastName(const Student& a, const Student& b);
	friend int compareCountry(const Student& a, const Student& b);
	friend int compareProvince(const Student& a, const Student& b);
};

typedef Student* StudentPtr;

class DomesticStudent:public Student
{
private:
	string first_name;
	string last_name;
	float CGPA;
	int research_score;
	int application_id;
	string province;
public:
	DomesticStudent();
	DomesticStudent(const string &, const string &, const float &, const int &, const string &, const int &);
	DomesticStudent(const DomesticStudent& s);
	string getFirst() const;
	string getLast() const;
	float getCGPA() const;
	int getResearch() const;
	string getProvince() const;
	string getCountry() const;
	ToeflScore getToefl() const;
	int getApplication() const;
	void set(const string&, const string&, const float&, const int&, const string&, const int&);
	void setFirst(const string &first);
	void setLast(const string &last);
	void setProvince(const string &prov);
	void setCGPA(const float &C);
	void setResearch(const int &research);
	void setApplication(const int &application);
	void print() const;
	DomesticStudent& operator = (const DomesticStudent& s);
	//overload operator, use to print out information
	friend ostream& operator << (ostream& outputStream, const DomesticStudent& s);
};

typedef DomesticStudent* D_StudentPtr;

class InternationalStudent:public Student
{
private:
	string first_name;
	string last_name;
	float CGPA;
	int research_score;
	int application_id;
	string country;
	ToeflScore toeflscore;
public:
	InternationalStudent();
	InternationalStudent(const string &, const string &, const string &, const ToeflScore& toefl, const float &, const int &, const int &);
	InternationalStudent(const InternationalStudent& s);
	string getFirst() const;
	string getLast() const;
	float getCGPA() const;
	int getResearch() const;
	string getProvince() const;
	string getCountry() const;
	ToeflScore getToefl() const;
	int getApplication() const;
	void set(const string&, const string&, const string&, const ToeflScore& toefl, const float&, const int&, const int&);
	void setFirst(const string& first);
	void setLast(const string& last);
	void setCountry(const string& coun);
	void setToefl(const ToeflScore& toefl);
	void setCGPA(const float& C);
	void setResearch(const int& research);
	void setApplication(const int& application);
	void print() const;
	InternationalStudent& operator = (const InternationalStudent& s);
	friend ostream& operator << (ostream& outputStream, const InternationalStudent& s);
};

typedef InternationalStudent* I_StudentPtr;

class Node
{
private:
	StudentPtr sPtr;
	Node* link;
public:
	Node();
	Node(StudentPtr sPtr, Node* link);
	~Node();

	StudentPtr getStudentPtr() const;
	Node* getLink() const;

	void setStudentPtr(StudentPtr sPtr);
	void setLink(Node* link);
};
typedef Node* NodePtr;

void sortArray(DomesticStudent* dStudent, InternationalStudent* iStudent, int dnum, int inum);

void Head_insert(NodePtr& h, StudentPtr s);
void Tail_insert(NodePtr& h, StudentPtr s);
void Insert_after(NodePtr& h, StudentPtr s);
void insert(NodePtr& h, D_StudentPtr s);
void insert(NodePtr& h, I_StudentPtr s);
void insertDomestic(NodePtr& h);
void insertInternationl(NodePtr& h);
void Insert_before(NodePtr& h, NodePtr&n, StudentPtr s);
void print_link(NodePtr& h);
void deleteExistNode(NodePtr& h);
void Head_insert(NodePtr& h, NodePtr& n);
void Insert_after(NodePtr& n1, NodePtr& n2);
void Insert_before(NodePtr& h, NodePtr& n1, NodePtr& n2);
void sortAll(NodePtr& h1, NodePtr& h2);
void searchMerged(NodePtr& h);
void searchID(NodePtr& h);
void searchCGPA(NodePtr& h);
void searchResearch(NodePtr& h);
void searchName(NodePtr& h);
void remove_front_tail(NodePtr& h);