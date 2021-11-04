#pragma once
#include <string>

using namespace std;

class Card
{
public:
	Card();
	Card(char val, int st);
	virtual ~Card();

	bool setCard(char val, char st); // Validating value and suit of the card
	char getValue(); // Return card's value --> A2345678910JQK
	char getSuit(); // Return card's suit --> Spade, Club, Heart, Diamond
	string to_string(); // Return card as string --> AH, 10C, 4D ect.
	bool isValid(); // Return true if card valid

private:
	char value; 
	char suit;


};

