// Dealer.cpp file for Blackjack game
// Final Project OOP COP 3003
// Professor Vanselow
// Creator: Spence Van Tiem 
// Date: 11/15/2021

#include "Dealer.h"

Dealer::Dealer() // LO1 // LO1C 
{
    deck = new Deck(shuffleNum);
    hand->addCard(dealCard());
    hand->addCard(dealCard());
    //constructor
}

Dealer::~Dealer()
{
    delete deck;
    //deconstructor 
}

Card* Dealer::dealCard()
{
    return deck->dealCard();
}

bool Dealer::canHit()
{
    if ((hand->getHighScore() >= dealNum) && hand->getHighScore() <= winNum)
    {
        return false;
    }
    else if (hand->getLowScore() < dealNum)
    {
        return true;
    }
}

int Dealer::stay()
{
    if (hand->getLowScore() >= dealNum)
    {
        return hand->getLowScore();
    }
    else
    {
        return hand->getHighScore();
    }
}

void Dealer::resetCheck()
{
    if (deck->getLeft() <= 10)
    {
        deck->resetDeck();
        deck->shuffle(shuffleNum);
    }
}

string Dealer::holeCardHand()
{
    string holeCard = "XX";
    string tempHand = hand->to_string();
    tempHand.erase(0, 2);
    tempHand.insert(0, holeCard);
    return tempHand;
}

