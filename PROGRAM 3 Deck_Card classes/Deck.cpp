#include <algorithm>

using namespace std;

#include "Deck.h"

/* Constructs a Deck of 52 cards:
   Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King of each suit.
   Cards should start off in this order with the order of suits being:
   Clubs, Diamonds, Hearts, Spades. So, the Card at the top of the
   Deck should be the Ace of Clubs.
   
   For best efficiency, the top of Deck should be stored at 
   back end of vector.
*/
Deck::Deck() {

   // make sure vector is empty
   theDeck.clear();
   dealtCards.clear();

   // add all spades to deck
   for (unsigned i = 13; i > 0; --i) {
      theDeck.push_back(Card('s',i));
   }
   // add all hearts to deck
   for (unsigned i = 13; i > 0; --i) {
      theDeck.push_back(Card('h',i));
   }
   // add all diamonds to deck
   for (unsigned i = 13; i > 0; --i) {
      theDeck.push_back(Card('d',i));
   }
   // add all clubs to deck
   for (unsigned i = 13; i > 0; --i) {
      theDeck.push_back(Card('c',i));
   }

}

/* Deals (returns) the top card of the deck. 
   Removes this card from theDeck and places it in dealtCards.
   As mentioned in comments for the constructor, 
   for best efficiency, the top card should come from the 
   back end of vector.
*/
Card Deck::dealCard() {
   dealtCards.push_back(theDeck.at(theDeck.size() - 1));
   theDeck.pop_back();

   return dealtCards.at(dealtCards.size() - 1);
}

/* Places all cards back into theDeck and shuffles them into random order.
   Use random_shuffle function from algorithm library.
   To pass test harness, this function must go forward through dealtCards
   pushing each Card onto the back end of theDeck, then clear dealtCards.
   Do not use pop_back on dealtCards.
*/
void Deck::shuffleDeck() {

   for (unsigned i = 0; i < dealtCards.size(); ++i) {
      theDeck.push_back(dealtCards.at(i));
   }
   dealtCards.clear();

   random_shuffle(theDeck.begin(), theDeck.end());

}

/* returns the size of the Deck (how many cards have not yet been dealt).
*/
unsigned Deck::deckSize() const {return theDeck.size();}
