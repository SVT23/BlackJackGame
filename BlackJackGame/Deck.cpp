// Deck .cpp file for blackjack game 
// Spence Van Tiem 
// COP 3003
// 11/24/21

#include "Deck.h"

using namespace std;

Deck::Deck() // LO1
{
    srand(time(0));
    create();
    //constructor
}

Deck::Deck(int timesShuffled)
{
    srand(time(0));
    create();
    shuffle(timesShuffled);
}

Deck::~Deck()
{
    for (int i = 0; i < Size; i++)
    {
        delete deck[i];
    }
    //deconstructor
}

void Deck::create()
{
    char suit[] = { 'C', 'S', 'H', 'D' };
    char value[] = { 'A', '2', '3', '4', '5',
                    '6', '7', '8', '9', 'T',
                    'J', 'Q', 'K' };

    int i = 0;
    for (int s = 0; s < (sizeof(suit) / sizeof(char)); s++)
        for (int v = 0; v < (sizeof(value) / sizeof(char)); v++)
        {
            deck[i] = new Card(value[v], suit[s]);
            i++;
        }

}

bool Deck::shuffle(int timesShuffled)
{
    Card* hold;
    int random = 0;
    const int minimum = 200;

    if (getUsed() == 0)
    {


        for (int i = 0; i < timesShuffled * minimum; i++)
        {
            random = rand() % (Size - 1);
            hold = deck[random];
            deck[random] = deck[random + 1];
            deck[random + 1] = hold;
        }
        return true;
    }
    else
    {
        cout << endl << "Error: Cannot shuffle deck" << endl;
        return false;
    }
}

Card* Deck::dealCard()
{
    Card* hold;
    int cardCount = 0;

    if (getUsed() == Size)
    {
        cardCount = (Size - 1);
    }
    else
    {
        cardCount = getUsed();
    }

    if (deck[cardCount] != NULL)
    {
        hold = deck[cardCount];
        deck[cardCount] = NULL;
        return hold;
    }
    else
    {
        cout << "\nError: No cards remaining in deck" << endl;
        return NULL;
    }

}

int Deck::getUsed()
{
    int used = 0;

    for (int i = 0; i < Size; i++)
    {
        if (deck[i] == NULL)
        {
            used++;
        }
    }

    return used;
}

int Deck::getLeft()
{
    return Size - getUsed();
}

string Deck::to_string()
{
    string name = "";

    const int suits = 4;
    const int values = 13;
    int card = 0;

    for (int s = 0; s < suits; s++)
    {
        for (int v = 0; v < values; v++)
        {

            if (deck[card] != NULL)
            {
                name += deck[card]->to_string();
                name += " ";
                card++;
            }
            else
            {
                card++;
            }
        }

        name += "\n";
    }

    return name;
}

void Deck::resetDeck()
{
    for (int i = 0; i < Size; i++)
    {
        delete deck[i];
    }
    create();
}

