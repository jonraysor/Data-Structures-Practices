//
//  MergeSort.h
//  Sorts
//
//  Created by Jonathan Raysor on 4/16/18.
//  Copyright © 2018 Jonathan Raysor. All rights reserved.
//

#ifndef MergeSort_h
#define MergeSort_h

// This function will merge two halves together in sorted order.
template <class T>
// the first parameter is the beginning of the first half, the second parameter is the end of the first half,
// the third parameter is the beginning of the second half, the fourth parameter is the end of the seocond half,
// the fifth and final parameter is the data set that the merged halves will go into.
static void merge(T * arr1, int n1, T * arr2, int n2, T* arrToReturn){
    
    // we dynamically allocate a temporary data set within the function to hold the final data set as we merge the data sets.
    int *temp = new int[n1+n2];
    
    // these integers will hold the current index in each data set as we iterate through them.
    int index1 = 0;
    int index2 = 0;
    
    // this integer will hold the current index of the temporary data set as we add to it.
    int index = 0;
    
    // this loop runs while we're not at the end of either data set.
    while(index1 < n1 && index2 < n2){
     
        // now we check to see if the current element in the first half is less than the current element in the second half
        if(arr1[index1] <= arr2[index2]){
            // if the condition is met we add the current element in the first half to the temporary array and increment our index in the first half.
            temp[index] = arr1[index1];
            index1++;
        }
        
        // if the condtition is not met we add the element from the second half to the array.
        else{
            temp[index] = arr2[index2];
            index2++;
        }
        
        // we must always increment the temporary array.
        index++;
    }
    
    // if we reach the end and we still have values in the first half we add them to the end of the temporary array.
    while(index1 < n1){
        temp[index] = arr1[index1];
        index1++;
        index++;
    }
    
    // if we reach the end and we still have values in the second half we add them to the end of the temporary array.
    while(index2 < n2){
        temp[index] = arr2[index2];
        index2++;
        index++;
    }
    
    // finally we add all the elements from the temporary array to the arrToReturn and delete the temporary array.
    for (int i = 0; i < index; i++){
        arrToReturn[i] = temp [i];
    }
    
    delete [] temp;
}

// This recursive function 'magically' sorts each half and merges all halves then merges the two big halves
template <class T>
void mergeSort(T * arr, int size){
    
    // base case, if arr can't be divided by two anymore (if it's size is is 1 or less) return.
    if(size <= 1)
        return;
    
    // this integer will hold the midpoiunt in arr which is ultimately used to divide arr.
    int middleElem = size/2;
    
    // sort the first half.
    mergeSort(arr,middleElem);
    // sort the right half.
    mergeSort(arr + middleElem, size-middleElem);
    // merge sorted halves.
    merge(arr,middleElem,arr+middleElem,size-middleElem,arr);
}


#endif /* MergeSort_h */
