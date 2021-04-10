#include <iostream>
using namespace std;

/* PROTOTYPES */
string** initDeck();
void printDeck(string **deck);
void cutDeck(string **deck);
void shuffleDeck(string **deck);
void copyDeck (string **src, string **dest);

/* GLOBALS */

string** initDeck() {
  string** deck = new string*[24];
  for(int i=0; i<24; i++){
      deck[i]= new string[2];
       
      if(i<6)
        deck[i][0]="S";
      
      else if(i<12)
        deck[i][0]="C";

      else if(i<18)
        deck[i][0]="H";

      else if(i<24)
        deck[i][0]="D";
      
      deck[i][1]= to_string((i % 6) + 2);
  }

  return deck;
}

// DO NOT MODIFY THESE FUNCTIONS
int main() {
  int numShuffles;
  string **deck = initDeck();
  cout << "Deck before shuffle: " << endl;
  printDeck(deck);
  cout << endl << "How many shuffles? ";
  cin >> numShuffles;
  cutDeck(deck);
  for (int i = 0; i < numShuffles; i++) {
    shuffleDeck(deck);
    printDeck(deck);
  }
  cutDeck(deck);
  cout << endl;
  cout << "Deck after shuffle: " << endl;
  printDeck(deck);
}

void printDeck(string **deck) {
  for (int i = 0; i < 24; i++){
    cout << deck[i][0] << deck[i][1] << " ";
  }
  cout << endl;
}

void copyDeck(string **src, string **dest) {
  for (int i = 0; i < 24; i++) {
    dest[i][0] = src[i][0];
    dest[i][1] = src[i][1];
  }
}

void cutDeck(string **deck) {
  string **temp = initDeck();
  for (int i = 0; i < 24; i++) {
    temp[i][0] = deck[(i + 12) % 24][0];
    temp[i][1] = deck[(i + 12) % 24][1];
  }
  copyDeck(temp, deck);
}

void shuffleDeck(string **deck) {
  string **temp = initDeck();
  for (int i = 0; i < 24; i++) {
    if (i % 2 == 0) {
      temp[i][0] = deck[(i / 2)][0];
      temp[i][1] = deck[(i / 2)][1];
    } else {
      temp[i][0] = deck[(i / 2) + 12][0];
      temp[i][1] = deck[(i / 2) + 12][1];
    }
  }
  copyDeck(temp, deck);
}
