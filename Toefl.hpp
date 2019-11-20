/*
 

Ensc 251
Dr Zhenman Fang
Diego Flores, Ansley Ang
September 25, 2019
Lab 1
Toefl.h

This file makes all the declarations for the ToeflScore class. ToeflScore is a class that returns a reading score, listening score, 
speaking score, writing score, and a total. Only International Students have this score. Each score can be 30 at highest, meaning 
the highest total can be 120.

*/
// We made a seperate file for the ToeflScore class so we could use it as a member of the InternationalStudent class

#ifndef Toefl_h
#define Toefl_h

using namespace std;

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

#endif
