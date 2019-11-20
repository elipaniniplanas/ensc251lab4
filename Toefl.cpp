/*

Ensc 251
Dr Zhenman Fang
Diego Flores, Ansley Ang
September 25, 2019
Lab 1
Toefl.cpp

This program declares the definition of each Constructor and function for the class ToeflScore

*/


#include "Toefl.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

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
