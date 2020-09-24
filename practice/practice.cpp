/*
PRACTICE

Program illustrates and displays functions with arrays as parameters.

practice.cpp
a4_1

Created by nyccowgirl on 9/24/20.
Copyright © 2020 nyccowgirl. All rights reserved.
*/

#include <iostream>
using namespace std;


bool noNegatives(const int array[], int size);
void absoluteValues(int array[], int size);
int eCount(const char array[], int size);
int charCount(const char array[], int size, char targetChar);
bool isSorted(const int array[], int size);
bool equalNeighbors(const char array[], int size);


int main(int argc, const char * argv[]) {
    int nums1[5] = {-2, -1, 0, 1, 2};
    int nums2[5] = {5, 4, 3, 2, 1};
    char char1[5] = {'a', 'z', 'e', 'e', 'x'};
    char char2[5] = {'a', 'b', 'c', 'd', 'z'};
    char target = 'z';
    
    cout << "noNegatives: " << noNegatives(nums1, 5) << " ";
    cout << noNegatives(nums2, 5) << endl;
    cout << "isSorted: " << isSorted(nums1, 5) << " ";
    cout << isSorted(nums2, 5) << endl;
    absoluteValues(nums1, 5);
    absoluteValues(nums2, 5);
    
    cout << "absoluteValues: {";
    for (int x = 0; x < 5; x++) {
        cout << nums1[x];
        
        if (x < 4) {
            cout << ", ";
        }
    }
    cout << "} {";
    for (int y = 0; y < 5; y++) {
        cout << nums2[y];
        
        if (y < 4) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
    
    cout << "eCount: " << eCount(char1, 5) << " " << eCount(char2, 5) << endl;
    cout << "charCount: " << charCount(char1, 5, target) << " ";
    cout << charCount(char2, 5, target) << endl;
    cout << "equalNeighbors: " << equalNeighbors(char1, 5) << " ";
    cout << equalNeighbors(char2, 5) << endl;

    return 0;
}






// Definition of function noNegatives. Function passes in an array and row size and returns
// false if any of the integers in the array is negative and true if none of the values are
// negative.

bool noNegatives(const int array[], int size) {
    for (int x = 0; x < size; x++) {
        if (array[x] < 0) {
            return false;
        }
    }
    
    return true;
}






// Definition of function absoluteValues. Function passes in an array and row size. It
// replaces all negative values with the corresponding positive value in the array.

void absoluteValues(int array[], int size) {
    for (int x = 0; x < size; x++) {
        if (array[x] < 0) {
            array[x] = -array[x];
        }
    }
}






// Definition of function eCount. Function passes in an array and row size. It returns the
// number of times the character 'e' is in the array.

int eCount(const char array[], int size) {
    char target = 'e';
    int total = 0;
    
    for (int x = 0; x < size; x++) {
        if (array[x] == target) {
            total++;
        }
    }
    
    return total;
}






// Definition of function charCount. Function passes in an array, row size and target
// character. It returns the number of times the target character is in the array.

int charCount(const char array[], int size, char targetChar) {
    int total = 0;
    
    for (int x = 0; x < size; x++) {
        if (array[x] == targetChar) {
            total++;
        }
    }
    
    return total;
}






// Definition of function isSorted. Function passes in an array and row size. It returns
// true if the array is sorted in ascending order, and false otherwise.

bool isSorted(const int array[], int size) {
    for (int x = 1; x < size; x++) {
        if (array[x] < array[x - 1]) {
            return false;
        }
    }
    
    return true;
}






// Definition of function equalNeighbors. Function passes in an array and row size. It
// returns true if there are two adjacent elements with equal values, and false otherwise.

bool equalNeighbors(const char array[], int size) {
    for (int x = 1; x < size; x++) {
        if (array[x] == array[x - 1]) {
            return true;
        }
    }
    
    return false;
}


/*
 
 noNegatives: 0 1
 isSorted: 1 0
 absoluteValues: {2, 1, 0, 1, 2} {5, 4, 3, 2, 1}
 eCount: 2 0
 charCount: 1 1
 equalNeighbors: 1 0
 Program ended with exit code: 0
 
 */
