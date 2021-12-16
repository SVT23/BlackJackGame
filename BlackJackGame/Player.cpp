// Player.cpp file for Blackjack game
// Final Project OOP COP 3003
// Professor Vanselow
// Creator: Spence Van Tiem 
// Date: 11/20/2021

#include "Player.h"


using namespace std;

Player::Player() // LO1 
{
    name = "Player";
    balance = 500;
    hand = new Hand;
    //constructor
}

Player::Player(string n, Card* c1, Card* c2) // LO1C
{
    name = n;
    balance = 500;
    hand = new Hand(c1, c2);

}

Player::~Player()
{
    delete hand;
    //deconstructor
}

string Player::getName()
{
    return name;
}

int Player::getBalance()
{
    return balance;
}

void Player::setBet(int b)
{
    bet = b;
}

int Player::getBet()
{
    return bet;
}

void Player::fixBalance(char outcome)
{
    if (outcome == 'w')
    {
        balance += bet;
    }
    else if (outcome == 'l')
    {
        balance -= bet;
    }
    else if (outcome == 'b')
    {
        balance += (bet * 3);
    }
    else
    {
        cout << "\nError fixing player balance" << endl;
    }
}

void Player::hit(Card* h)
{
    hand->addCard(h);
}

int Player::stand()
{
    if (hand->getHighScore() <= winNum)
    {
        return hand->getHighScore();
    }
    else
    {
        return hand->getLowScore();
    }
}

string Player::showHand()
{
    return hand->to_string();
}
