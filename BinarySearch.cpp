//
//  main.cpp
//  BinarySearch
//
//  Created by Nkechi Iregbulem on 2/27/19.
//  Copyright © 2019 Nkechi Iregbulem. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
#include <algorithm>
#include <functional>

// Binary Search Algorithm to return the value of key at given index of an array
int BinarySearch( int array[], int arraySize, int key) {
    int mid_val, low_val = 0, high_val = arraySize - 1;
    
    while (high_val >= low_val) {
        mid_val = (high_val + low_val)/2;
        if (array[mid_val] < key) {
            low_val = mid_val + 1;
        }
        else if(array[mid_val] > key) {
            high_val = mid_val - 1;
        }
        else {
            return mid_val;
        }
        return -1; // if not found
    }
    
}
    


int main() {
    
   const int array[] = {12, 24, 36, 48, 60, 72, 84, 96, 108 };
    const int arraySize = 9;
    int i, key, keyIndex;
    cout << "Enter a value " << endl; cin >> key;
    keyIndex = BinarySearch(array, arraySize, key);
    if (keyIndex == -1 ) {
        cout << key << " was not found" << endl;
    }
    else {
        cout << key << " at index " << keyIndex << "." << endl;
    }
    
    

    
    
    return 0;
}
