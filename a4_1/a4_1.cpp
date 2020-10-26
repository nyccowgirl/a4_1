/*
 Trang Hoang
 CS110B
 Dave Harden
 9/24/20
 a4_1.cpp
 
 Assignment 4.1
 
 Program reads five or more cards from user, analyzes the cards and prints out the highest
 category of poker hand that it represents: four of a kind, full house, straight, three of
 a kind, two pairs, pair, and high card.
 
 Created by nyccowgirl on 9/24/20.
 Copyright © 2020 nyccowgirl. All rights reserved.
*/

#include <iostream>
using namespace std;

const int LOW = 2;                          // Defines lowest value that a card can have
const int HIGH = 9;                         // Defines highest value that a card can have
const int NUM_INT = (HIGH - LOW + 1);       // Defines range of values that a card can have
int COUNT[NUM_INT] = {0};                   // Defines initialization of count array
const int NUM_CARDS = 5;                    // Defines initial no. of cards (to be modified
                                            // for test cases)

//int getNumCards();
void getCards(int hand[]);
void validateInput(int &card, int cardNum);
void countCards(const int hand[]);
bool containsFourOfaKind(const int hand[]);
bool containsFullHouse(const int hand[]);
bool containsStraight(const int hand[]);
bool containsThreeOfaKind(const int hand[]);
bool containsTwoPair(const int hand[]);
bool containsPair(const int hand[]);

int main(int argc, const char * argv[]) {
    int hand[NUM_CARDS];                    // Holds array of cards for a hand
        
//    getNumCards();                    // Comment out to address global variable vs constant
    getCards(hand);
    countCards(hand);
    
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






// COMENT OUT TO REMOVE GLOBAL VARIABLE VS. CONSTANT SINCE WE CAN'T CHANGE SIGNATURE TO
// ADJUST THE SIZE OF ARRAY IN BOOL FUNCTIONS
// Definition of getNumCards. Function gets user input for number of cards to be played in
// a hand, validates it to ensure that there is at least one card and assigns it to global
// variable, which was initially assigned a high number for memory allocation purposes.

//int getNumCards() {
//    do {
//        cout << "Enter the number of cards to be dealt in a hand: ";
//        cin >> NUM_CARDS;
//
//        if (NUM_CARDS < 1) {
//            cout << "Invalid input: A hand cannot have less than 1 card." << endl;
//        }
//    } while (NUM_CARDS < 1);
//    return NUM_CARDS;
//}






// Definition of getCards. Function passes in an uninitialized array of integers and uses
// a global variable/constant for size of hand. It gets the user input for each card in a
// hand with integer values from LOW to HIGH (e.g., 2 to 9) and stores it into the array.

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






// Definition of function validateInput. Function passes in a card value inputted from user
// to validate and the card number in the hand. It determines if the value is between LOW
// and HIGH (e.g., 2 to 9). If not, it asks for user to input a new card and passes it as a
// reference variable.

void validateInput(int &card, int cardNum) {
    
    while (!(card >= LOW && card <= HIGH)) {
        cout << "Invalid input: Cards can only be between ";
        cout << LOW << " and " << HIGH << "." << endl;
        cout << "Card " << cardNum << ": ";
        cin >> card;
    }
}






// Definition of function countCards. Function passes in array of cards (hand). It counts
// the number of each value (e.g., 2 to 9) and stores it into the global COUNT array.

void countCards(const int hand[]) {
    
    for (int x = 0; x < NUM_CARDS; x++) {
        COUNT[hand[x] - LOW]++;
    }
}






// Definition of function containsFourOfaKind. Function passes in array of cards. It
// traverses the global COUNT array to determine if there is a four of a kind and returns
// true. Otherwise, it returns false. Note in the functions testing for the type of hand,
// greater than or equal to (>=) is used rather than equal to (==) to cover all possible
// hand values for the number. This captures test cases where there are larger hands (e.g.,
// for 7-card hand containing 3 4s and 3 5s; the second three of a kind in
// count array would not be viewed as a possible pair for a full house if it is only
// considered a three of a kind (== 3) and not a possible pair (>= 2) as well. Since the
// if/else statement in the main function looks for highest value hand first, there
// wouldn't be a risk of 3 4s and 3 5s being treated as 2-pair hand as the winning hand
// with >= vs. ==.

bool containsFourOfaKind(const int hand[]) {
        
    for (int x = 0; x < NUM_INT; x++) {
        if (COUNT[x] >= 4) {
            return true;
        }
    }
    return false;
}






// Definition of function containsFullHouse. Function passes in array of cards. It calls
// functions containsThreeOfaKind and containsTwoPair to determine if there is a full
// house. See additional note in function containsFourOfaKind. Since a three of a kind could
// also be viewed as a pair, calling function containsTwoPair would account for the
// duplication in a value that had 3+ cards to ensure another value had a pair of cards to
// complete the full house.

bool containsFullHouse(const int hand[]) {
    
    if (containsThreeOfaKind(hand) && containsTwoPair(hand)) {
        return true;
    }
    return false;
}






// Definition of function containsStraight. Function passes in array of cards. It
// traverses the global COUNT array to determine if there is a straight and returns true.
// Otherwise, it returns false. For hands larger than five cards, sequence is restarted to
// zero when a number does not have a card to ensure that the card number value is in
// sequential order up to five. See additional note in function containsFourOfaKind.

bool containsStraight(const int hand[]) {
    int sequence = 0;
    
    for (int x = 0; x < NUM_INT; x++) {
        if (COUNT[x] > 0) {
            sequence++;
        } else {
            sequence = 0;
        }
        
        if (sequence == 5) {
            return true;
        }
    }
    return false;
}






// Definition of function containsThreeOfaKind. Function passes in array of cards. It
// traverses the global COUNT array to determine if there is a three of a kind and returns
// true. Otherwise, it returns false. See additional note in function containsFourOfaKind.

bool containsThreeOfaKind(const int hand[]) {
    
    for (int x = 0; x < NUM_INT; x++) {
        if (COUNT[x] >= 3) {
            return true;
        }
    }
    return false;
}






// Definition of function containsTwoPairs. Function passes in array of cards. It
// traverses the global COUNT array to determine if there are two pairs and returns true.
// Otherwise, it returns false. See additional note in function containsFourOfaKind.

bool containsTwoPair(const int hand[]) {
    int pair = 0;
        
    for (int x = 0; x < NUM_INT; x++) {
        if (COUNT[x] >= 2) {
            pair++;
        }
        
        if (pair == 2) {
            return true;
        }
    }
    return false;
}






// Definition of function containsPair. Function passes in array of cards. It traverses the
// global COUNT array to determine if there is a pair and returns true. Otherwise, it
// returns false. See additional note in function containsFourOfaKind.

bool containsPair(const int hand[]) {
    
    for (int x = 0; x < NUM_INT; x++) {
        if (COUNT[x] >= 2) {
            return true;
        }
    }
    return false;
}


/*
 
 Enter 5 numeric cards, no face cards. Use 2 - 9.
 Card 1: 8
 Card 2: 7
 Card 3: 8
 Card 4: 2
 Card 5: 7
 Two Pairs!
 Program ended with exit code: 0
 
 Enter 5 numeric cards, no face cards. Use 2 - 9.
 Card 1: 8
 Card 2: 7
 Card 3: 4
 Card 4: 6
 Card 5: 5
 Straight!
 Program ended with exit code: 0
 
 Enter 5 numeric cards, no face cards. Use 2 - 9.
 Card 1: 9
 Card 2: 2
 Card 3: 3
 Card 4: 4
 Card 5: 5
 High Card!
 Program ended with exit code: 0
 
 Enter 6 numeric cards, no face cards. Use 2 - 9.
 Card 1: 5
 Card 2: 6
 Card 3: 6
 Card 4: 5
 Card 5: 6
 Card 6: 5
 Full House!
 Program ended with exit code: 0
 
 Enter 7 numeric cards, no face cards. Use 2 - 9.
 Card 1: 1
 Invalid input: Cards can only be between 2 and 9.
 Card 1: 2
 Card 2: 6
 Card 3: 5
 Card 4: 4
 Card 5: 8
 Card 6: 7
 Card 7: 9
 Straight!
 Program ended with exit code: 0
 
 Enter 5 numeric cards, no face cards. Use 2 - 9.
 Card 1: 2
 Card 2: 5
 Card 3: 3
 Card 4: 8
 Card 5: 7
 High Card!
 Program ended with exit code: 0
 
 Enter 5 numeric cards, no face cards. Use 2 - 9.
 Card 1: 2
 Card 2: 5
 Card 3: 3
 Card 4: 5
 Card 5: 7
 One Pair!
 Program ended with exit code: 0
 
 Enter 5 numeric cards, no face cards. Use 2 - 9.
 Card 1: 2
 Card 2: 5
 Card 3: 3
 Card 4: 5
 Card 5: 3
 Two Pairs!
 Program ended with exit code: 0
 
 Enter 5 numeric cards, no face cards. Use 2 - 9.
 Card 1: 5
 Card 2: 5
 Card 3: 3
 Card 4: 5
 Card 5: 7
 Three of a Kind!
 Program ended with exit code: 0
 
 Enter 5 numeric cards, no face cards. Use 2 - 9.
 Card 1: 3
 Card 2: 5
 Card 3: 6
 Card 4: 4
 Card 5: 7
 Straight!
 Program ended with exit code: 0
 
 Enter 5 numeric cards, no face cards. Use 2 - 9.
 Card 1: 5
 Card 2: 7
 Card 3: 5
 Card 4: 7
 Card 5: 7
 Full House!
 Program ended with exit code: 0
 
 Enter 5 numeric cards, no face cards. Use 2 - 9.
 Card 1: 2
 Card 2: 5
 Card 3: 5
 Card 4: 5
 Card 5: 5
 Four of a Kind!
 Program ended with exit code: 0
 
 */
