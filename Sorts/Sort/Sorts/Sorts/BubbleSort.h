//
//  BubbleSort.h
//  Sorts
//
//  Created by Jonathan Raysor on 4/29/18.
//  Copyright © 2018 Jonathan Raysor. All rights reserved.
//

#ifndef BubbleSort_h
#define BubbleSort_h

// This function uses nested loops to sort a data set.
template <class T>
// it accepts the address to the beginning of the data set and the size of said data set.
void bubbleSort(T * arr, int size){
    
    // the first loop begins with the first element in the data set and iterates through it one by one.
    for(int i=0; i < size - 1; i++)
        // the second loop stays ahead of the first loop by one element.
        for(int j = i + 1; j < size; j++){
            // as both loops are meeting their given conditions a comparison is done between the jth and ith element.
            if (arr[j] < arr[i]){
            // if the jth element is less than the ith element we need to swap the two to put the array in order. We acciomplish this by using a temp and holding on to one value while swapping it with the other.
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
}

#endif /* BubbleSort_h */
