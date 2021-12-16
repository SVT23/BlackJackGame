// Game.cpp file for Blackjack game
// Final Project OOP COP 3003
// Professor Vanselow
// Creator: Spence Van Tiem 
// Date: 11/25/2021

#include "Game.h"
#include <iomanip>
#include <ostream>

using namespace std;

Game::Game() // LO1
{
    dealer = new Dealer;
    player = new Player;
    //constructor
}

Game::Game(string n)
{
    dealer = new Dealer;
    player = new Player(n, dealer->dealCard(), dealer->dealCard());
}

Game::~Game()
{
    delete player;
    delete dealer;
    //deconstructor
}

void Game::newHand()
{
    dealer->resetCheck();

    if (dealer->hand->getHandSize() == 0)
    {
        dealer->hit(dealer->dealCard());
        dealer->hit(dealer->dealCard());
        player->hit(dealer->dealCard());
        player->hit(dealer->dealCard());
    }
}

int Game::getBalance()
{
    return player->getBalance();
}

void Game::makeBet(int bet)
{
    player->setBet(bet);
}

void Game::showHoleCard()
{
    cout << "\nDealer Hand:" << endl;
    cout << dealer->holeCardHand() << endl;

    cout << "\nPlayer Hand:" << endl;
    cout << player->showHand() << "[" << player->hand->getLowScore() << "/" << player->hand->getHighScore() << "]" << endl;
}

void Game::showBothHand()
{
    cout << "\nDealer Hand:" << endl;
    cout << dealer->showHand() << "[" << dealer->hand->getLowScore() << "/" << dealer->hand->getHighScore() << "]" << endl;

    cout << "\nPlayer Hand:" << endl;
    cout << player->showHand() << "[" << player->hand->getLowScore() << "/" << player->hand->getHighScore() << "]" << endl;
}

bool Game::getPlayerBJ()
{
    return player->hand->isBJ();
}

bool Game::getDealerBJ()
{
    return dealer->hand->isBJ();
}

void Game::playerHit()
{
    player->hit(dealer->dealCard());
}

void Game::dealerHit()
{
    dealer->hit(dealer->dealCard());
}

bool Game::getPlayerBust()
{
    return player->hand->bust();
}

bool Game::canDealerHit()
{
    return (dealer->hand->canHit()) && (dealer->canHit());
}

bool Game::canPlayerHit()
{
    return player->hand->canHit();
}

void Game::outcomes()
{
    if (player->hand->bust())
    {
        cout << endl << "You busted." << endl;
        cout << "You lose $" << player->getBet() << endl;
        player->fixBalance('l');
        cout << "Your current balance is: $" << player->getBalance() << endl;
    }

    else if (!(player->hand->isBJ()) && (dealer->hand->isBJ()))
    {
        cout << endl << "Dealer has a BlackJack!" << endl;
        cout << "You lose $" << player->getBet() << endl;
        player->fixBalance('l');
        cout << "Your current balance is: $" << player->getBalance() << endl;
    }
    else if ((player->hand->isBJ()) && !(dealer->hand->isBJ()))
    {
        cout << endl << "BlackJack!!! You win!" << endl;
        cout << "You win triple your bet of " << player->getBet() << endl;
        player->fixBalance('b');
        cout << "Your current balance is: $" << player->getBalance() << endl;
    }
    else if ((player->hand->isBJ()) && (dealer->hand->isBJ()))
    {
        cout << endl << "Push" << endl;
        cout << "Your current balance is: $" << player->getBalance() << endl;
    }

    else if (!(player->hand->bust()) && (dealer->hand->bust()))
    {
        cout << endl << "Dealer busted, you win!" << endl;
        cout << "You win $" << player->getBet() << endl;
        player->fixBalance('w');
        cout << "Your current balance is: $" << player->getBalance() << endl;
    }

    else if ((dealer->stay() > player->stand()) && !(player->hand->isBJ()) && !(dealer->hand->isBJ()))
    {
        cout << endl << "Dealer wins." << endl;
        cout << "You lose $" << player->getBet() << endl;
        player->fixBalance('l');
        cout << "Your current balance is: $" << player->getBalance() << endl;
    }
    else if ((dealer->stay() < player->stand()) && !(player->hand->isBJ()) && !(dealer->hand->isBJ()))
    {
        cout << endl << "You win!" << endl;
        cout << "You win $" << player->getBet() << endl;
        player->fixBalance('w');
        cout << "Your current balance is: $" << player->getBalance() << endl;
    }

    else if (dealer->stay() == player->stand())
    {
        cout << endl << "Push." << endl;
        cout << "Your current balance is: $" << player->getBalance() << endl;
    }
}

void Game::clearHands()
{
    dealer->hand->clearHand();
    player->hand->clearHand();
}

