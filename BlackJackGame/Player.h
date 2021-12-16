// Player.h Blackjack game
// Final Project OOP COP 3003
// Professor Vanselow
// Creator: Spence Van Tiem 
// Date: 11/20/2021 

// LO1A

#pragma once
#include "Card.h"
#include "Hand.h"
#include "Deck.h"
#include <string>


class Player // LO1
{
public: // LO1C // LO1B // LO6
    Player();
    Player(string n, Card* c1, Card* c2);
    virtual ~Player();

    Hand* hand; //pointer to hand object
    string getName(); //return player name
    string showHand(); //return cards in player hand
    int getBalance(); //return balance of player
    void setBet(int bet); //set player bet
    int getBet(); //return bet ammount
    void hit(Card* h); //add card to player hand and return true if allowed, false if not
    int stand(); //return score after standing
    void fixBalance(char outcome); //changes balance depending on outcome of game


protected: // LO1C // LO6
    string name;
    int balance;
    int bet;
    static const int winNum = 21;

private:

};


