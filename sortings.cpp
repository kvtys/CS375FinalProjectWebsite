#include <stdlib.h>
#include <iostream>

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

void selectionSort(int arr[], int size){ //Sorts in ascending order in O(n^2)
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

void insertionSort(int arr[], int size){ //Sorts in ascending order in O(n^2), can be O(n) in some cases
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

void bubbleSort(int arr[], int size) //Sorts in ascending order in O(n^2), can be O(n) in some cases
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

int main(int argc, char * argv[]){

    cout << "Sorting.. In Main:" << endl;
    int arr[4] = {3,2,1,4};

    printArr(arr, 4);
    bubbleSort(arr, 4);
    printArr(arr, 4);


    return 0;
}