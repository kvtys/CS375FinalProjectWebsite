#pragma once

#include <iostream>
#include <stdlib.h>
#include <chrono>
#include "sortSource.h"

class sortJect{
    private:
        int *arr = nullptr; //Dynamic Array
        int capacity;
    public:
        sortJect(int capacity);
        sortJect();
        ~sortJect();
        void extend(int capacity = 10); //Only Extends Array Size
        void shuffleArr(int limit = 100); //Shuffle is not automatic, so be warned!!
        void printArr();
        int getCapacity();
        double trackSelectionSort();
        double trackInsertionSort();
        double trackBubbleSort();
        double trackQuickSort();
        double trackMergeSort();

};