/*
 Trang Hoang
 CS110B
 Dave Harden
 9/24/20
 a4_1.cpp
 
 Assignment 4.1
 
 Program reads five or more cards from user, analyzes the cards and prints out the category
 of poker hand that it represents: four of a kind, full house, straight, three of a kind,
 two pairs, pair, and high card.
 
 Created by nyccowgirl on 9/24/20.
 Copyright © 2020 nyccowgirl. All rights reserved.
*/

#include <iostream>
using namespace std;

const int LOW = 2;                          // Defines lowest value that a card can have
const int HIGH = 9;                         // Defines highest value that a card can have
const int NUM_INT = (HIGH - LOW + 1);       // Defines range of values that a card can have
int NUM_CARDS = 1;                          // Defines initial no. of cards to get from user


void getNumCards();
void getCards(int hand[]);
void validateInput(int &card, int cardNum);
void countCards(const int hand[], int countCards[]);
bool containsFourOfaKind(const int hand[]);
bool containsFullHouse(const int hand[]);
bool containsStraight(const int hand[]);
bool containsThreeOfaKind(const int hand[]);
bool containsTwoPair(const int hand[]);
bool containsPair(const int hand[]);

int main(int argc, const char * argv[]) {
    int hand[NUM_CARDS];                    // Holds array of cards for a hand
    
//    cout << "";            // What about a cout causes program to not work for cards > 6?
    
    getNumCards();
    getCards(hand);
    
    if (containsFourOfaKind(hand)) {
        cout << "Four of a Kind!" << endl;
    } else if (containsFullHouse(hand)) {
        cout << "Full House!" << endl;
    } else if (containsStraight(hand)) {
        cout << "Straight!" << endl;
    } else if (containsThreeOfaKind(hand)) {
        cout << "Three of a Kind!" << endl;
    } else if (containsTwoPair(hand)) {
        cout << "Two Pairs!" << endl;
    } else if (containsPair(hand)) {
        cout << "One Pair!" << endl;
    } else {
        cout << "High Card!" << endl;
    }
    
    return 0;
}






// Definition of getNumCards. Function gets user input for number of cards to be played in
// a hand, validates it to ensure that there is at least one card and assigns it to global
// variable.

void getNumCards() {
    do {
        cout << "Enter the number of cards to be dealt in a hand: ";
        cin >> NUM_CARDS;
        
        if (NUM_CARDS < 1) {
            cout << "Invalid input: A hand cannot have less than 1 card." << endl;
        }
    } while (NUM_CARDS < 1);
}






// Definition of getCards. Function passes in an uninitialized array of integers and uses
// a global variable for size of hand. It gets the user input for each card in a hand with
// integer values from LOW to HIGH (e.g., 2 to 9) and stores it into the array.

void getCards(int hand[]) {
    int card;
    
    cout << "Enter " << NUM_CARDS << " numeric cards, no face cards. ";
    cout << "Use " << LOW << " - " << HIGH << "." << endl;
    
    for (int x = 0; x < NUM_CARDS; x++) {
        cout << "Card " << (x + 1) << ": ";
        cin >> card;
        validateInput(card, x + 1);
        hand[x] = card;
    }
}






// Definition of function validateInput. Function passes in a card and the card number to
// validate. It determines if it is between LOW to HIGH (e.g., 2 to 9). If not, it asks for
// user to input a new card and passes it as a reference variable.

void validateInput(int &card, int cardNum) {
    while (!(card >= LOW && card <= HIGH)) {
        cout << "Invalid input: Cards can only be between ";
        cout << LOW << " and " << HIGH << "." << endl;
        cout << "Card " << cardNum << ": ";
        cin >> card;
    }
}






// Definition of function countCards. Function passes in array of cards (hand) and array to
// count the cards in the hand (count). It initializes the count array as 0 and counts the
// number of each value (2 to 9) and stores it into the count array and passes it back by
// reference.

void countCards(const int hand[], int count[]) {
    
    for (int x = 0; x < NUM_CARDS; x++) {
        count[hand[x] - LOW]++;
    }
    
//    cout << "count = {";
//    for (int x = 0; x < NUM_INT; x++) {
//        if (x == (NUM_INT - 1)) {
//            cout << count[x] << "}" << endl;
//        } else {
//            cout << count[x] << ", ";
//        }
//    }
    
}






// Definition of function containsFourOfaKind. Function passes in array of cards. It calls
// function countCards to count number of each value (2 to 9) and determines if there is
// a four of a kind and returns true. Otherwise, it returns false.

bool containsFourOfaKind(const int hand[]) {
    int count[NUM_INT] = {0};
    
    countCards(hand, count);
    
    for (int x = 0; x < NUM_INT; x++) {
        if (count[x] >= 4) {
            return true;
        }
    }
    return false;
}






// Definition of function containsFullHouse. Function passes in array of cards. It calls
// function countCards to count number of each value (2 to 9) and determines if there is
// a full house (3 of a kind and pair) and returns true. Otherwise, it returns false.

bool containsFullHouse(const int hand[]) {
    int count[NUM_INT] = {0};
    bool threeOfaKind = false, pair = false;
    
    countCards(hand, count);
    
    for (int x = 0; x < NUM_INT; x++) {
        if (!threeOfaKind && count[x] >= 3) {
            threeOfaKind = true;
        } else if (count[x] >= 2) {
            pair = true;
        }
        
        if (threeOfaKind && pair) {
            return true;
        }
    }
    return false;
}






// Definition of function containsStraight. Function passes in array of cards. It calls
// function countCards to count number of each value (2 to 9) and determines if there is
// a straight and returns true. Otherwise, it returns false.

bool containsStraight(const int hand[]) {
    int count[NUM_INT] = {0};
    int straight = 0;
    
    countCards(hand, count);
    
    for (int x = 0; x < NUM_INT; x++) {
        if (count[x] > 0) {
            straight++;
        } else {
            straight = 0;
        }
        
        if (straight == 5) {
            return true;
        }
    }
    return false;
}






// Definition of function containsThreeOfaKind. Function passes in array of cards. It calls
// function countCards to count number of each value (2 to 9) and determines if there is
// a three of a kind and returns true. Otherwise, it returns false.

bool containsThreeOfaKind(const int hand[]) {
    int count[NUM_INT] = {0};
    
    countCards(hand, count);
    
    for (int x = 0; x < NUM_INT; x++) {
        if (count[x] >= 3) {
            return true;
        }
    }
    return false;
}






// Definition of function containsTwoPairs. Function passes in array of cards. It calls
// function countCards to count number of each value (2 to 9) and determines if there are
// two pairs and returns true. Otherwise, it returns false.

bool containsTwoPair(const int hand[]) {
    int count[NUM_INT] = {0};
    int pair = 0;
    
    countCards(hand, count);
    
    for (int x = 0; x < NUM_INT; x++) {
        if (count[x] >= 2) {
            pair++;
        }
        
        if (pair == 2) {
            return true;
        }
    }
    return false;
}






// Definition of function containsPair. Function passes in array of cards. It calls
// function countCards to count number of each value (2 to 9) and determines if there is
// a pair and returns true. Otherwise, it returns false.

bool containsPair(const int hand[]) {
    int count[NUM_INT] = {0};
    
    countCards(hand, count);
    
    for (int x = 0; x < NUM_INT; x++) {
        if (count[x] >= 2) {
            return true;
        }
    }
    return false;
}


/*
 
 Enter the number of cards to be dealt in a hand: 5
 Enter 5 numeric cards, no face cards. Use 2 - 9.
 Card 1: 8
 Card 2: 7
 Card 3: 8
 Card 4: 2
 Card 5: 7
 Two Pairs!
 Program ended with exit code: 0
 
 Enter the number of cards to be dealt in a hand: 5
 Enter 5 numeric cards, no face cards. Use 2 - 9.
 Card 1: 8
 Card 2: 7
 Card 3: 4
 Card 4: 6
 Card 5: 5
 Straight!
 Program ended with exit code: 0
 
 Enter the number of cards to be dealt in a hand: 5
 Enter 5 numeric cards, no face cards. Use 2 - 9.
 Card 1: 9
 Card 2: 2
 Card 3: 3
 Card 4: 4
 Card 5: 5
 High Card!
 Program ended with exit code: 0
 
 Enter the number of cards to be dealt in a hand: 0
 Invalid input: A hand cannot have less than 1 card.
 Enter the number of cards to be dealt in a hand: 6
 Enter 6 numeric cards, no face cards. Use 2 - 9.
 Card 1: 5
 Card 2: 6
 Card 3: 6
 Card 4: 5
 Card 5: 6
 Card 6: 5
 Full House!
 Program ended with exit code: 0
 
 Enter the number of cards to be dealt in a hand: 7
 Enter 7 numeric cards, no face cards. Use 2 - 9.
 Card 1: 2
 Card 2: 6
 Card 3: 5
 Card 4: 4
 Card 5: 8
 Card 6: 7
 Card 7: 9
 (lldb)
 
 */

/*
 DEBUGGING:
 
 Result without cout in main:
 
 Enter the number of cards to be dealt in a hand: 7
 Enter 7 numeric cards, no face cards. Use 2 - 9.
 Card 1: 2
 Card 2: 6
 Card 3: 5
 Card 4: 4
 Card 5: 8
 Card 6: 7
 Card 7: 9
 (lldb)
 
 Result with cout in main:
 
 0
 Enter the number of cards to be dealt in a hand: 7
 Enter 7 numeric cards, no face cards. Use 2 - 9.
 Card 1: 2
 Card 2: 6
 Card 3: 5
 Card 4: 4
 Card 5: 8
 Card 6: 7
 Card 7: 9
 Straight!
 Program ended with exit code: 0
 
 */
