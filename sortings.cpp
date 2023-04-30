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
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high){ //O(n^2) but usually O(nlogn)
    if(low < high){
        int qP = qPartition(arr, low, high);
        quickSort(arr, low, qP-1); //QS left
        quickSort(arr, qP+1, high); //QS right
    }
}



int main(int argc, char * argv[]){

    cout << "Sorting.. In Main:" << endl;
    int arr[4] = {3,2,1,4};

    printArr(arr, 4);
    quickSort(arr, 0, 3);
    printArr(arr, 4);


    return 0;
}