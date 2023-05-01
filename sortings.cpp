#include <stdlib.h>
#include <iostream>
#include <chrono>

using namespace std;

void printArr(int arr[], int size){
   
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return;
}

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void selectionSort(int arr[], int size){ // O(n^2)
    int temp;

    for(int i = 0; i < size-1; i++){
        for(int j = i+1; j < size; j++){
            if(arr[i] > arr[j]){
                swap(arr, i, j);
            }
        }
    }

    return;
}

void insertionSort(int arr[], int size){ // O(n^2), can be O(n) in some cases
    int key, j;
    for(int i = 1; i < size; i++){
        key = arr[i];
        j = i-1;

        while(arr[j] > key && j >= 0){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

void bubbleSort(int arr[], int size) // O(n^2), can be O(n) in some cases
{
    int temp;
    for(int i = 1; i < size; ++i)     
    {   
        for(int j = 0; j < (size - i); ++j)  
        {   
            if(arr[j] > arr[j + 1]){
                swap(arr, j, j+1);
            }
        }
    }
}

int qPartition(int arr[], int low, int high){
    int piv = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < piv) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i+1, high);
    return i + 1;
}

void quickSort(int arr[], int low, int high){ //O(n^2) but usually O(nlogn)
    if(low < high){
        int qP = qPartition(arr, low, high);
        quickSort(arr, low, qP-1); //QS left
        quickSort(arr, qP+1, high); //QS right
    }
}

void merge(int arr[], int low, int middle, int high){
    int x = 0;
    int y = 0;
    int z = low; //0 on first iteration

    int sizeSub1 = middle - low + 1;
    int sizeSub2 = high - middle;

    int sub1[sizeSub1];
    int sub2[sizeSub2];

    for(int i = 0; i < sizeSub1; i++){
        sub1[i] = arr[low+i];
    }
    for(int j = 0; j < sizeSub2; j++){
        sub2[j] = arr[middle+1+j];
    } //Initializing SubArray Data

    while(x < sizeSub1 && y < sizeSub2){ //Begin to prepare to merge SubArrays
        if(sub1[x] <= sub2[y]){arr[z] = sub1[x]; x++;}
        else{arr[z] = sub2[y]; y++;}
        z++;
    }   

    while(x < sizeSub1){ //Remnant Merge from sub1
        arr[z] = sub1[x];
        x++;
        z++;
    }

    while(y < sizeSub2){ //Remnant Merge from sub2
        arr[z] = sub2[y];
        y++;
        z++;
    }

}

void mergeSort(int arr[], int low, int high){ //O(nlogn) guarantee
    if(low < high){
        int middle = (low + high) / 2;
        mergeSort(arr, low, middle);
        mergeSort(arr, middle + 1, high);
        merge(arr, low, middle, high);
    }
}


void randomizeArr(int arr[], int size){
    for(int i = 0; i < size; i++){
        arr[i] = rand() % 100;
    }
}

double trackSelectionSort(int arr[], int size){
    auto start = std::chrono::high_resolution_clock::now();
    selectionSort(arr, size);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count();
}

double trackInsertionSort(int arr[], int size){
    auto start = std::chrono::high_resolution_clock::now();
    insertionSort(arr, size);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count();
}

double trackBubbleSort(int arr[], int size){
    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort(arr, size);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count();
}

double trackQuickSort(int arr[], int low, int high){
    auto start = std::chrono::high_resolution_clock::now();
    quickSort(arr, low, high);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count();
}

double trackMergeSort(int arr[], int low, int high){
    auto start = std::chrono::high_resolution_clock::now();
    mergeSort(arr, low, high);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count();
}


int main(int argc, char * argv[]){

    cout << "Sorting.. In Main:" << endl;
    //int size = 100000000; //1 Billion
    //int arr[size]; cant fit a billion on the stack
    //int size = 100000; //Hundred Thousand Takes Over a Minute Total Execution
    //int size = 10000; //Ten Thousand Takes About a second total
    int size = 20000;
    //int size = 10; 
    int *arr = new int[size];
    randomizeArr(arr, size);
    
    double time = trackSelectionSort(arr, size);
    cout << "selectionSort Execution Time: " <<  time << endl;

    randomizeArr(arr, size);

    time = trackInsertionSort(arr, size);
    cout << "insertionSort Execution Time: " << time << endl;


    randomizeArr(arr, size);

    time = trackBubbleSort(arr, size);
    cout << "bubbleSort Execution Time: " << time << endl;

    randomizeArr(arr, size);
   
    time = trackQuickSort(arr, 0, size-1);
    cout << "quickSort Execution Time: " << time << endl;

    randomizeArr(arr, size);

    time = trackMergeSort(arr, 0, size-1);
    cout << "mergeSort Execution Time: " << time << endl;

    return 0;
}