// BlackJackGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Spence Van Tiem 
// Main function to the final project --> Blackjack game
// 12/1/21
// COP 3003

#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Dealer.h"
#include "Player.h"
#include "Hand.h"
#include "Game.h"
#include <iomanip>
#include <string>

using namespace std;

// LO7 --> iterators and other operations on aggregates, including operations that take functions as arguments can be found throughout. 
// An iterator is an object (like a pointer) that points to an element inside the container.
// We can use iterators to move through the contents of the container.They can be
// visualised as something similar to a pointer pointing to some locationand we can
// access content at that particular location using them.
// https://home.csulb.edu/~pnguyen/cecs282/lecnotes/iterators.pdf

char getMenuChoice(string prompt, string letter) //Additional check if input is greater than single character, then check if input is a valid response
{
    string s = "";
    bool valid = false;

    do
    {
        cout << prompt << endl;
        cin >> s;

        if (s.length() == 1)
        {
            for (int i = 0; i < (int)letter.length(); i++)
                if (toupper(letter.at(i)) == toupper(s.at(0)))
                {
                    i = letter.length();
                    valid = true;
                }
        }
        if (!valid)
        {
            cout << "Error: Invalid input" << endl;
        }

    } while ((s.length() != 1) || (!valid));

    return s.at(0);

}

int main()
{
    int bet = 0;
    string playerName = "";
    char choice = 'x';
    char gameChoice = 'x';

    cout << "Welcome to the BlackJack table!" << endl << endl;
    choice = getMenuChoice("For a complete list of the rules enter (R/r),\nenter (P/p) to play, or enter (Q/q) to quit.\n", "rpq");

    if ((choice == 'R') || (choice == 'r'))
    {
        cout << "A player makes his/her bet before cards are dealt" << endl;
        cout << "Two cards are dealt to the player, both face up" << endl;
        cout << "Two cards are dealt to the dealer, one face up, one face down" << endl;
        cout << "The player may hit (draw cards) until: " << endl;
        cout << "1. The player no longer wants to hit" << endl;
        cout << "2. The player's low score is greater than or equal to 21" << endl;
        cout << "If the player busts, the dealer wins and the player loses their bet" << endl;
        cout << "When the player decides to stand, and hasn't bust, the dealer reveals the face down card" << endl;
        cout << "The dealer then draws cards as long as their score is not greater than 17" << endl;
        cout << "If the dealer's high score would be above 17 but lower than 21, the dealer must stay" << endl;
        cout << "If the dealer's high score would be over 21, but their low score would be lower than 17, the dealer draws another card" << endl;
        cout << "The deck will be reset after the the hand is completed after the deck falls below 10 cards" << endl;
        cout << "The game ends when the player is out of money or decides to leave table" << endl << endl;
        choice = getMenuChoice("Enter (P/p) to play, or enter (Q/q) to quit.\n", "pq");
        cout << choice << endl;

    }
    //Begin the game if P/p is chosen
    if ((choice == 'P') || (choice == 'p'))
    {
        cout << "\n\nPlease enter your first name:";

        cin >> playerName;

        Game* game = new Game(playerName);


        cout << "Welcome " << playerName << "!\n";

        //Begin do loop for continued play.
        do
        {
            game->newHand();

            //Display balance and ask user for bet.
            cout << "\n\nYou have $" << game->getBalance() << endl;
            cout << "How much would you like to bet?\n";

            cin >> bet;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(256, '\n');
                bet = -1;
            }

            //Input validation
            while ((bet <= 0) || (bet > game->getBalance()))
            {
                cout << "Invalid input. Please enter a bet greater than zero,\n";
                cout << "and less than your total balance.\n";

                cin >> bet;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(256, '\n');
                    bet = -1;
                }

            }

            game->makeBet(bet);

            game->showHoleCard();

            //If player has Blackjack skip asking the player to hit or stay.
            if (game->getPlayerBJ())
            {
                cout << "BLACKJACK!!\n";
                gameChoice = 's';
            }
            else //If player doesn't have Blackjack ask if player wants to hit or stay.
            {
                do //Begin loop for player to continue to take cards.
                {
                    //Input validation.
                    gameChoice = getMenuChoice("Would you like to hit (H/h), or stay (S/s)? : ", "hs");



                    //If player chooses H/h allow player to take a card.
                    if ((gameChoice == 'H') || (gameChoice == 'h'))
                    {
                        game->playerHit();
                        game->showHoleCard();

                    }

                    //After taking a card determine if the player's hand has busted
                    //if so gameChoice is set to 's' to drop out of do loop.
                    if (game->getPlayerBust())
                    {
                        cout << "\n--->BUST!!<---\n";
                        gameChoice = 's';
                    }

                    //Continue the loop as long as the hand isn't busted and the player hasn't chosen to stay.
                } while (((gameChoice == 'H') || (gameChoice == 'h')) &&
                    (game->canPlayerHit()));
            }

            if (!game->getPlayerBust())
            {

                //After player has chosen to say, the dealer shows the hole card.
                cout << "\n\nDealer shows their hole card.\n";

                game->showBothHand();


                //If the player hasn't busted and the dealer doesn't have Blackjack
                //the dealer can draw cards
                if (!game->getPlayerBust() && !game->getPlayerBJ())
                {
                    //if the dealer's score is <17, has <5 cards then the dealer takes a card.
                    while (game->canDealerHit())
                    {
                        cout << "\n\nDealer takes a card.";

                        game->dealerHit();

                        game->showBothHand();

                    }
                }

            } //If not busted

            //Determine the outcome of the game.
            game->outcomes();

            //After the outcome is determined, the hands are cleared.
            game->clearHands();

            //If the player is out of money, the game shuts down automatically.
            if (game->getBalance() <= 0)
            {
                cout << "You've run out of money! The game will now end.\n";
                choice = 'q';
            }
            //If the player has money ask if the player wants to continue playing.
            else
            {
                choice = getMenuChoice("Enter (Y/y) to continue playing, or (Q/q) to quit.\n", "yq");

            }
        } while ((choice == 'Y') || (choice == 'y'));

        //After the game is over delete the game.
        delete game;
    }





    return 0;
}












 