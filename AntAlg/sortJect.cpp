#include "sortJect.h"
#include <chrono> //chrono is being stubborn
using namespace std;

sortJect::sortJect(int capacity){
    this->capacity = capacity;
    this->arr = new int[capacity];
}

sortJect::sortJect(){
    this->capacity = 10;
    this->arr = new int[capacity];
}

sortJect::~sortJect(){
    delete [] arr;
}

void sortJect::extend(int capacity){ 
    if(capacity <= this->capacity){capacity = this->capacity;}
    int oldCapacity = this->capacity;
    this->capacity = capacity;
    int* arr2 = new int[capacity];
    for(int i = 0; i < oldCapacity; i++){
        arr2[i] = arr[i];
    }
    delete [] arr;
    arr = arr2;
    arr2 = nullptr;
}

void sortJect::shuffleArr(int limit){
    for(int i = 0; i < capacity; i++){
        arr[i] = rand() % limit; //Limit gives the upper range of random numbers. EX: 0 - > limit
    }
}

void sortJect::printArr(){
    for(int i = 0; i < capacity; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int sortJect::getCapacity(){
    return this->capacity;
}

double sortJect::trackSelectionSort(){
    auto start = std::chrono::high_resolution_clock::now();
    selectionSort(arr, capacity);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count();
}

double sortJect::trackInsertionSort(){
    auto start = std::chrono::high_resolution_clock::now();
    insertionSort(arr, capacity);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count();
}

double sortJect::trackBubbleSort(){
     auto start = std::chrono::high_resolution_clock::now();
    bubbleSort(arr, capacity);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count();
}

double sortJect::trackQuickSort(){
    auto start = std::chrono::high_resolution_clock::now();
    quickSort(arr, 0, capacity-1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count();
}

double sortJect::trackMergeSort(){
    auto start = std::chrono::high_resolution_clock::now();
    mergeSort(arr, 0, capacity-1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count();
}


