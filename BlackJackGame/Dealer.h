// Dealer.h file for Blackjack game 
// Final Project OOP COP 3003
// Professor Vanselow
// Creator: Spence Van Tiem 
// Date: 11/15/2021

// LO1A

#pragma once
#include "Player.h"
#include "Card.h"
#include "Hand.h"
#include "Deck.h"


class Dealer : public Player // LO1 // LO2 // LO2a  --> Dealer is a player. Dealer inherits from the player class 
                                                // Public mode: If we derive a sub class from a public base class. 
                                                // Then the public member of the base class will become public in the derived class 
                                                // and protected members of the base class will become protected in derived class.
                                                // https://www.geeksforgeeks.org/inheritance-in-c/
{
public: // LO1C // LO1B // LO6 // LO3 --> dynamic dispatch is the process of selecting which implementation of a polymorphic operation 
                                    // (method or function) to call at run time. 
                                    // It is commonly employed in, and considered a prime characteristic of, object-oriented programming (OOP) languages and systems
                                    // https://en.wikipedia.org/wiki/Dynamic_dispatch
    Dealer();
    virtual ~Dealer();
    Card* dealCard(); //pointer to a card object to be dealt to hand
    bool canHit(); //returns bool if dealer can hit or not
    int stay(); //returns best score for dealer
    string holeCardHand(); //shows the dealers hand with XX as hole card
    void resetCheck(); //checks cards in deck, if <10 then call deck reset function

protected:

private: // LO1C /// LO6
    //dealer creates and manages the deck
    Deck* deck;
    static const int dealNum = 17;
    static const int shuffleNum = 20;
};

