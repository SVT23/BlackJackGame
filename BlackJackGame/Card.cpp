// Card.cpp file for Blackjack game
// Final Project OOP COP 3003
// Professor Vanselow
// Creator: Spence Van Tiem 
// Date: 11/15/2021

#include "Card.h"
#include <string>

using namespace std;

Card::Card() { //LO1 //LO1C
	value = '0';
	suit = '0';

}

Card::Card(char val, int st) {
	value = val;
	suit = st;

	if (!isValid()) {
		value = '0';
		suit = '0';
	}
}

Card::~Card() {

}

bool Card::isValid() {
	return (((value>=50) && (value <= 57)) || (value == 'A') || (value == 'T') ||
        (value == 'J') || (value == 'Q') || (value == 'K'))
        && ((suit == 'C') || (suit == 'S') || (suit == 'H') || (suit == 'D'));
}

bool Card::setCard(char val, char st)
{
    value = val;
    suit = st;

    if (isValid())
    {
        return true;
    }
    else
    {
        value = '0';
        suit = '0';
        return false;
    }
}

char Card::getValue()
{
    return value;
}

char Card::getSuit()
{
    return suit;
}

string Card::to_string()
{
    string name = "";
    name += value;
    name += suit;
    return name;


}
