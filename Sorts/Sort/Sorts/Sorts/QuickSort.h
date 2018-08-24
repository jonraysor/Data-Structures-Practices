//
//  QuickSort.h
//  Sorts
//
//  Created by Jonathan Raysor on 4/25/18.
//  Copyright © 2018 Jonathan Raysor. All rights reserved.
//

#ifndef QuickSort_h
#define QuickSort_h
using namespace std;


//This fucntion will swap the two elements when the while loop is broken in QuickSort::partition().
template <class T>
// this function is labled static so it can not be accessed outside of QuickSort_h
static void swap(T* a, T* b){
    T t = *a;
    *a = *b;
    *b = t;
}

//This function partitions the array checking if the conditions are met. If a condition is not met a swap is done.
template <class T>
// this function is labled static so it can not be accessed outside of QuickSort_h
static int partition(T *arr, int left, int right, T pivot){
    
    // while the two 'pointers' don't meet eachother the loop will run.
    while (left <= right){
        
        // while the value of the pointer is less than the pivot (meets the condition) iteration will continue from the left side to the middle.
        while(arr[left] < pivot){
            left++;
        }
        
        // while the value of the pointer is greater than the pivot (meets the condition) iteration will continue from the right side to the middle.
        while(arr[right] > pivot){
            right--;
        }
        
        // if this step is reached that means that the data set is out of order and elements need to be swapped.
        // if the left 'pointer' is less than or equal to the right 'pointer' we will swap the values of the two 'pointers'.
        if (left <= right){
            swap(arr+left, arr+right);
            left++;
            right--;
        }
        
    }
    // we're returning the left 'pointer' which represents the midpoint between the left and right side. Also known as the index in QuickSort::quickSort().
    return left;
}



//This recursive function sorts the data set using the QuickSort::partition() and QuickSort::quickSort().
template <class T>
    void quickSort(T *arr, int left, int right){
        
    // this is our base case for the recursive function.
        // if the left 'pointer' is equal to the right pointer that means there's no more calls to QuickSort::partition() and we can start to go back down the stack (recursion).
    if(left == right)
        return;
        
        // for the purpose of this implementation we used the middle element in the data set as the pivot.
        T pivot = arr[(left+right)/2];
        
        // the index shows where the left side ends and where the right side begins
        int index = partition(arr, left, right, pivot);
        
        // we will first sort the left half of the data set.
        quickSort(arr,left, index-1);
        // then we will sort the right half of the data set.
        quickSort(arr, index, right);
}

#endif /* QuickSort_h */
