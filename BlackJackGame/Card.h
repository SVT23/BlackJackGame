// Card.h file for Blackjack game
// Final Project OOP COP 3003
// Professor Vanselow
// Creator: Spence Van Tiem 
// Date: 11/15/2021

// LO1A

#pragma once
#include <string>

using namespace std;

class Card // LO1 // LO4 this learning concept is applicable to all of the classes within this program --> 
							// “ Functional programming (FP) is a programming paradigm — 
							// a style of building the structure and elements of computer programs 
							//	— that treats computation as the evaluation of mathematical functions 
							// and avoids changing-state and mutable data.” — Wikipedia
							// “ Object - oriented programming(OOP) is a programming paradigm based on the concept of “objects”, 
							// which may contain data, in the form of fields, often known as attributes;and code, in the form of procedures, 
							// often known as methods.” — Wikipedia
							// “ Procedural programming is a programming paradigm, derived from structured programming, 
							// based upon the concept of the procedure call.Procedures, also known as routines, subroutines, or functions, 
							// simply contain a series of computational steps to be carried out.” — Wikipedia
{
public: // LO1C // LO1B // LO6
	Card();
	Card(char val, int st);
	virtual ~Card();

	bool setCard(char val, char st); // Validating value and suit of the card
	char getValue(); // Return card's value --> A2345678910JQK
	char getSuit(); // Return card's suit --> Spade, Club, Heart, Diamond
	string to_string(); // Return card as string --> AH, 10C, 4D ect.
	bool isValid(); // Return true if card valid

private: // LO6
	char value; 
	char suit;


};

