#ifndef TOEFLSCORE_HPP
#define TOEFLSCORE_HPP
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
//ToeflScore class is used to be able to access and set the different fields of the total toefl score
//for each international student, which includes seperate reading, writing, listening and speaking scores
class ToeflScore
{
public:
	//constructor
//pre condition: input values for initializing private member variables
//post condition: initialized private member variables
	ToeflScore(int read, int listen, int speak, int write);

	//default constructor
	//post condition: inititalizes toefl member variables to default values 
	ToeflScore();

	//pre condition: pass integer value for reading score
	//post condition: assigns the passed value to private member variable reading
	void set_reading(int read);

	//post condition: returns toefl reading score integer
	int get_reading() const;

	//pre condition: pass integer value for writing score
	//post condition: assigns the passed value to private member variable writing
	void set_writing(int write);

	//post condition: returns toefl writing score integer
	int get_writing() const;

	//pre condition: paas integer value for speaking score
	//post condition: assigns the passed value to provate member variable speaking
	void set_speaking(int speak);

	//post condition: returns toefl speaking score integer
	int get_speaking() const;

	//pre condition: pass integer value for listening score
	//post condition: assings the pased value to private member variable listening
	void set_listening(int listen);

	//post condition: retruns toefl listening score integer
	int get_listening() const;

	//pre condition: passes 4 integer parameters representing individual toefl scores
	//post condition: assigns the sum of the scores to the private member varibale total
	void set_total(int read, int listen, int speak, int write);

	//post condition: returns total toefl score as integer
	int get_total() const;

	//post condition: error checks if the 4 scores are valid, and if not, exits the program.
	void errorcheck();

private:
	//private members are all variables, for encapsulation/creating ADT
	int reading;
	int writing;
	int speaking;
	int listening;
	int total;
};
#endif