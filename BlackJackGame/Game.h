// Game.h Blackjack game
// Final Project OOP COP 3003
// Professor Vanselow
// Creator: Spence Van Tiem 
// Date: 11/25/2021

// LO1A

#pragma once
#include "Player.h"
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Dealer.h"

using namespace std;

class Game // LO1
{
public: // LO1C // LO1B // LO6
    Game();
    Game(string name);
    virtual ~Game();

    void newHand(); //Checks if deck needs reset, if not, deals out cards to empty hands
    int getBalance(); // return balance of player
    void makeBet(int bet); //sets the players bet
    void showHoleCard(); //shows both hands with dealers hole card face down
    void showBothHand(); //shows both hands with hole card turned over
    bool getPlayerBJ(); //returns bool if player has bj
    bool getDealerBJ(); //returns bool if dealer has bj
    void playerHit(); //add card to player hand
    void dealerHit(); //add card to dealer hand
    bool getPlayerBust(); //return bool if player busted
    bool canPlayerHit(); //return bool if player can hit
    bool canDealerHit(); //return bool if dealer can hit
    void outcomes(); //gets outcome of the game
    void clearHands(); //clears both hands

protected: // LO6
    Player* player; //pointer to player object
    Dealer* dealer; //pointer to dealer object

private:
};
