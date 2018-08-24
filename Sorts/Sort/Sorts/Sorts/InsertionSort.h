//
//  InsertionSort.h
//  Sorts
//
//  Created by Jonathan Raysor on 4/29/18.
//  Copyright © 2018 Jonathan Raysor. All rights reserved.
//

#ifndef InsertionSort_h
#define InsertionSort_h

// This function sorts a given data set by setting a key which comes after all elements starting from 0 and compares the key and swaps.
template <class T>
// this function takes in a data set and it's size
void insertionSort(T * arr, int size){
    
    // interger to hold the spot in the data set for the key.
    int key;
    // variable used for inner loop
    int j;
    
    // the initial loop starts at the first element so it can be compared to the 0th element at the beginning
    for (int i = 1; i < size; i++){
        
        // key is equal to the current ith position
        key = arr[i];
        // j is set to the element before the ith element
        j = i - 1;
        
        // we make sure that j is at least at the 0th element and is greater than the key
        while(j >= 0 && arr[j] > key){
            // if the above conditions are met we the value of the element (j+1) becomes equal to j
            arr[j+1] = arr[j];
            // then we move j back another element to check if we need to continue changing arr[j+1]
            j--;
        }
        // finally, when j becomes out of bounds or it's not greater than the key j+1 = key.
        arr[j+1] = key;
    }
}

#endif /* InsertionSort_h */
