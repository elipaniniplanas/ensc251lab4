#include "toeflScore.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;
//TOEFL SCORE DEFINITION

//ToeflScore constructor where the 4 scores are initialized, and the total score
//is initialized as their sum.
ToeflScore::ToeflScore(int read, int listen, int speak, int write)
{
	writing = write;
	reading = read;
	speaking = speak;
	listening = listen;
	total = writing + reading + speaking + listening;
	errorcheck(); //error checking function call
}

//the default toeflscore constructor to initialize all the scores to 0;
ToeflScore::ToeflScore()
{
	writing = 0;
	reading = 0;
	speaking = 0;
	listening = 0;
	total = 0;
}

//The error checking function of class toeflscore, where each of the
//4 scores is checked to be between 0 and 30. Note the total score is not
//checked to be between 0 and 120, because if it were to be larger than 120 or less 
//than 0, then that would be as a result of an error in one of the scores.
void ToeflScore::errorcheck()
{
	if ((writing < 0) || (writing > 30))
	{
		cout << "Error: Invalid Writing Score. Exiting program";
		exit(-1);
	}

	if ((reading < 0) || (reading > 30))
	{
		cout << "Error: Invalid Reading Score. Exiting program";
		exit(-1);
	}

	if ((speaking < 0) || (speaking > 30))
	{
		cout << "Error: Invalid Speaking Score. Exiting program";
		exit(-1);
	}

	if ((listening < 0) || (listening > 30))
	{
		cout << "Error: Invalid Listening Score. Exiting program";
		exit(-1);
	}
}

//mutator/set function for reading score, includes error check so that even
//if the initalized value was error checked, any new values entered after the 
//initialization are checked to be valid
void ToeflScore::set_reading(int read)
{
	reading = read;
	if ((reading < 0) || (reading > 30))
	{
		cout << "Error: Invalid Reading Score. Exiting program";
		exit(-1);
	}
}

//accessor/get function for reading score
int ToeflScore::get_reading() const
{
	return(reading);
}

//mutator/set function for writing score, also checks for valdity of entry
void ToeflScore::set_writing(int write)
{
	writing = write;
	if ((writing < 0) || (writing > 30))
	{
		cout << "Error: Invalid Writing Score. Exiting program";
		exit(-1);
	}
}

//acessor/get function for the writing score
int ToeflScore::get_writing() const
{
	return(writing);
}

//mutaotr/set function for the speaking score, ensuring passed value is valid
void ToeflScore::set_speaking(int speak)
{
	speaking = speak;
	if ((speaking < 0) || (speaking > 30))
	{
		cout << "Error: Invalid Speaking Score. Exiting program";
		exit(-1);
	}
}

//accessor/get function for speaking score
int ToeflScore::get_speaking() const
{
	return(speaking);
}

//mutator/set function for listening score, where the score passed is 
//checked to be within the valid range
void ToeflScore::set_listening(int listen)
{
	listening = listen;
	if ((listening < 0) || (listening > 30))
	{
		cout << "Error: Invalid Listening Score. Exiting program";
		exit(-1);
	}
}

//accessor/get function for the listening score
int ToeflScore::get_listening() const
{
	return(listening);
}

//mutator/set function for the total score, where the 4 parameters are the individual
//scores and are summed to get the total. There is no error checking involved since 
//the four scores were each individually check for validity prior.
void ToeflScore::set_total(int read, int listen, int speak, int write)
{
	total = reading + writing + listening + speaking;
}

//accessor/get function for the total toefl score
int ToeflScore::get_total() const
{
	return(total);
}