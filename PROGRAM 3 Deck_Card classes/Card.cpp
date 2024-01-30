using namespace std;

#include "Card.h"
 
/* Assigns a default value of 2 of Clubs
*/
Card::Card() : suit('c'), rank(2) {}

/* Assigns the Card the suit and rank provided.
   suits: c = Clubs, d = Diamonds, h = Hearts, s = Spades
   If an invalid suit is provided, sets the suit to Clubs
   ranks: 1 - 13 (1 = Ace, 11 = Jack, 12 = Queen, 13 = King)
   If an invalid rank is provided, sets the rank to 2
   Accepts lower or upper case characters for suit
*/
Card::Card(char userSuit, int userRank) {

   // account for capitalized suit parameter
   if (userSuit == 'C') {
      suit = 'c';
   }
   else if (userSuit == 'D') {
      suit = 'd';
   }
   else if (userSuit == 'H') {
      suit = 'h';
   }
   else if (userSuit == 'S') {
      suit = 's';
   }
   // handle invalid suit parameter
   else if (userSuit != 'c' && userSuit != 'd' && userSuit != 'h' && userSuit != 's') {
      suit = 'c';
   }
   // vaid suit parameter
   else {
      suit = userSuit;
   }

   // rank out of range
   if (userRank < 1 || userRank > 13) {
      rank = 2;
   }
   else {
      rank = userRank;
   }
}

// Returns the Card's suit
char Card::getSuit() const {return suit;}

// Returns the Card's rank as an integer
int Card::getRank() const {return rank;}

/* Outputs a Card in the following format: Rank of Suit
   For example, if the rank is 3 and the suit is h: 3 of Hearts
   Or, if the rank is 1 and the suit is d: Ace of Diamonds
   Or, if the rank is 11 and the suit is c: Queen of Clubs
   etc.
*/
ostream & operator<<(ostream &cardOut, const Card &card) {
   string outSuit = "";
   string outRank = "";

   // assignment of suit string
   if (card.suit == 'c') {
      outSuit = "Clubs";
   }
   else if (card.suit == 'd') {
      outSuit = "Diamonds";
   }
   else if (card.suit == 'h') {
      outSuit = "Hearts";
   }
   else if (card.suit == 's') {
      outSuit = "Spades";
   }

   // assignment of rank string
   if (card.rank == 1) {
      outRank = "Ace";
   }
   else if (card.rank == 2) {
      outRank = "2";
   }
   else if (card.rank == 3) {
      outRank = "3";
   }
   else if (card.rank == 4) {
      outRank = "4";
   }
   else if (card.rank == 5) {
      outRank = "5";
   }
   else if (card.rank == 6) {
      outRank = "6";
   }
   else if (card.rank == 7) {
      outRank = "7";
   }
   else if (card.rank == 8) {
      outRank = "8";
   }
   else if (card.rank == 9) {
      outRank = "9";
   }
   else if (card.rank == 10) {
      outRank = "10";
   }
   else if (card.rank == 11) {
      outRank = "Jack";
   }
   else if (card.rank == 12) {
      outRank = "Queen";
   }
   else if (card.rank == 13) {
      outRank = "King";
   }

   cardOut << outRank << " of " << outSuit;

   return cardOut;
}
