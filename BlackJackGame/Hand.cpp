// Hand .cpp file for blackjack game 
// Spence Van Tiem 
// COP 3003 
// 11/10/21

#include "Hand.h"
#include <iostream>

using namespace std;

Hand::Hand()
{
    for (int i = 0; i <= Size; i++)
    {
        hand[i] = NULL;
    }
    //ctor
}

Hand::Hand(Card* c1, Card* c2)
{
    for (int i = 0; i <= Size; i++)
    {
        hand[i] = NULL;
    }

    hand[0] = c1;
    hand[1] = c2;

}

Hand::~Hand()
{
    //dtor
}

bool Hand::addCard(Card* card)
{
    if (canHit())
    {
        hand[getHandSize()] = card;
        return true;
    }
    else
    {
        cout << "\nError: Unable to hit" << endl;
        return false;
    }
}

int Hand::getHandSize()
{
    int handSize = 0;
    for (int i = 0; i < Size; i++)
    {
        if (hand[i] != NULL)
        {
            handSize++;
        }
    }
    return handSize;
}

int Hand::getHighScore()
{
    int highScore = 0;
    bool firstAce = false;
    for (int i = 0; i < getHandSize(); i++)
    {
        if ((hand[i]->getValue() == 'T') || (hand[i]->getValue() == 'J')
            || (hand[i]->getValue() == 'Q') || (hand[i]->getValue() == 'K'))
        {
            highScore += 10;
        }
        else if (hand[i]->getValue() == 'A' && !firstAce)
        {
            highScore += 11;
            firstAce = true;
        }
        else if (hand[i]->getValue() == 'A' && firstAce)
        {
            highScore += 1;
        }
        else
        {
            highScore += (hand[i]->getValue() - '0');
        }
    }
    return highScore;
}

int Hand::getLowScore()
{
    int lowScore = 0;

    for (int i = 0; i < getHandSize(); i++)
    {
        if ((hand[i]->getValue() == 'T') ||
            (hand[i]->getValue() == 'J') ||
            (hand[i]->getValue() == 'Q') ||
            (hand[i]->getValue() == 'K'))
        {
            lowScore += 10;
        }
        else if (hand[i]->getValue() == 'A')
        {
            lowScore += 1;
        }
        else
        {
            lowScore += (hand[i]->getValue() - '0');
        }
    }

    return lowScore;

}

bool Hand::canHit()
{
    return ((!bust() && !handFull()) && (getLowScore() != Win));
}

bool Hand::handFull()
{
    return (getHandSize() == Size);

}

bool Hand::bust()
{
    return (getLowScore() > Win);

}

void Hand::clearHand()
{
    for (int i = 0; i < Size; i++)
    {
        delete hand[i];
    }
    for (int i = 0; i <= Size; i++)
    {
        hand[i] = NULL;
    }
}

bool Hand::isBJ()
{
    if (getHandSize() == 2)
    {
        return ((hand[0]->getValue() == 'A') &&
            ((hand[1]->getValue() == 'T') ||
                (hand[1]->getValue() == 'K') ||
                (hand[1]->getValue() == 'Q') ||
                (hand[1]->getValue() == 'J'))
            ||
            ((hand[1]->getValue() == 'A') &&
                ((hand[0]->getValue() == 'T') ||
                    (hand[0]->getValue() == 'K') ||
                    (hand[0]->getValue() == 'Q') ||
                    (hand[0]->getValue() == 'J'))));
    }
    else
    {
        return false;
    }

}

string Hand::to_string()
{
    string cards = "";

    for (int i = 0; i < getHandSize(); i++)
    {
        cards += hand[i]->to_string() + " ";

    }
    return cards;
}
