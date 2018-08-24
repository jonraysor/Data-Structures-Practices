//
//  main.cpp
//  Sorts
//
//  Created by Jonathan Raysor on 4/16/18.
//  Copyright © 2018 Jonathan Raysor. All rights reserved.
//

#include <iostream>
#include "QuickSort.h"
#include "BubbleSort.h"
#include "MergeSort.h"
#include "InsertionSort.h"

int main(int argc, const char * argv[]) {
   
    int numbers[6];
    
    for (int i =0; i < 5; i ++){
        std::cout << "Enter a random number" << std::endl;
        std:: cin >> numbers[i];
    }
    
    quickSort(numbers,0, 5);
    
    for (int i=0; i <5; i++){
        std::cout << numbers[i] << std::endl;
    }
}
