#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

#include "Deck.h"
#include "Card.h"

// Returns true if vector of Cards passed in contains at least 2 Cards with the same rank.
bool hasPair(const vector<Card> &hand);

// Sends to output stream a hand of Cards on a single line, 
// each Card separated by a comma.
// If the vector is empty, do not output anything.
// Example (vector size of 3): Ace of Spades, Two of Hearts, King of Clubs 
ostream & operator<<(ostream &handOut, const vector<Card> &hand);

int main() {
    srand(2222);
    ostringstream outSS;
    ofstream outFS;
    string userInput = "";
    string fileName = "";
    unsigned numCards = 0;
    unsigned numDeals = 0;
    double numMatch = 0.0;
    Deck simDeck;
    vector<Card> hand(0);

    // handle user wanting to safe output to file
    do {

    cout << "Do you want to output all hands to a file?(Yes/No) ";
    cin >> userInput;
    cout << endl;

    } while (userInput != "Yes" && userInput != "No");

    if (userInput == "Yes") {

        cout << "Enter name of output file: ";
        cin >> fileName;
        cout << endl;

    }

    // prompt user for number of cards per hand
    cout << "Enter number of cards per hand: ";
    cin >> numCards;
    cout << endl;

    cout << "Enter number of deals (simulations): ";
    cin >> numDeals;
    cout << endl;

    // run simulation
    for (unsigned i = 0; i < numDeals; ++i) {

        simDeck.shuffleDeck();

        // deal user-speciifed number of cards
        for (unsigned j = 0; j < numCards; ++j) {
            hand.push_back(simDeck.dealCard());
        }
        // check if any suits match
        if (hasPair(hand)) {

            // count hands that have a match
            ++numMatch;
            // prepend exclamation
            outSS << "Found Pair!! ";

        }
        else {
            outSS << "             ";
        }
        // append hand to sring stream
        outSS << hand << endl;

        // put cards in hand back into deck
        hand.clear();

    }

    // output hands to user-specified file
    outFS.open(fileName);
    outFS << outSS.str();

    cout << "Chances of receiving a pair in a hand of " << numCards << " cards is: " << ( numMatch * 100.0 ) / ( numDeals * 1.0 ) << "%";

    return 0;
}


/*--------------------function definitions--------------------*/

bool hasPair(const vector<Card> &hand) {
    int currRank = 0;

    // iterate through cards in hand starting at beginning
    for (unsigned i = 0; i < hand.size(); ++i) {

        // assign temp with rank of card at index i
        currRank = hand.at(i).getRank();

        // interate through cards in hand starting at index i
        for (unsigned j = i + 1; j < hand.size(); ++j) {
            
            // compare rank of card at index i to card at index j
            if (currRank == hand.at(j).getRank()) {

                // return true at first instance of a match
                return true;

            }

        }

    }

    // if none match, return false
    return false;
}

ostream & operator<<(ostream &handOut, const vector<Card> &hand) {
    unsigned i = 0;

    for (i = 0; i < hand.size() - 1; ++i) {
        handOut << hand.at(i) << ", ";
    }
    handOut << hand.at(i);

    return handOut;
}
