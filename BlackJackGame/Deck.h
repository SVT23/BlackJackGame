// Deck .h file for the blackjack game
// Spence Van Tiem 
// COP 3003
// 11/12/21
#pragma once
#include <string>
#include <iostream>
#include "Card.h"
#include <ctime>
#include <cstdlib>

using namespace std;

class Deck
{
public:
    Deck();
    Deck(int timesShuffled);
    virtual ~Deck();

    Card* dealCard(); //returns pointer to card object taken from top of deck
    bool shuffle(int timesShuffled); //shuffle if no cards have been dealt after reset
    int getUsed(); // get number of cards that have been dealt out of deck
    int getLeft();// get number of cards still in deck
    void resetDeck(); //resets deck back to 52 unshuffled cards
    string to_string(); //displays cards in deck and will not have cards previously dealt


protected:

private:
    static const int Size = 52;
    Card* deck[Size];
    void create(); //creates a full unshuffled deck
};


