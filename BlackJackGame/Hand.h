// Hand .h file for blackjack game 
// Spence Van Tiem 
// COP 3003 Final Project
// 11/10/21

// LO1A

#pragma once
#include "Card.h"
#include <string>

using namespace std;

class Hand // LO1
{
public: // LO1C // LO1B // LO6
    Hand();
    Hand(Card* c1, Card* c2);
    virtual ~Hand();

    bool addCard(Card* card);//return false if: low score is >= 21, or hand is full, return true if card is added
    int getHandSize(); //return number of cards in hand
    int getHighScore(); //return score with first ace as 11 instead of 1
    int getLowScore(); // return score with all aces as 1
    void clearHand(); //clears hand, deletes cards in hand
    bool bust(); //return true if lowscore is above 21
    bool handFull(); //return true if hand has 5 cards in it
    bool canHit(); //return true if hand can take another card
    bool isBJ(); //return true if hand is bj
    string to_string(); //displays cards in hand

protected:

private: // LO6
    static const int Size = 5;
    static const int Win = 21;

    Card* hand[Size];
};

