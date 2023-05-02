#include "sortJect.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){ //Some Demonstrated Use of the Class "sortJect"

    sortJect arr1(1000000); //Array Size 10000

    cout << "In Main: Testing sortJect via Randomized Array[" << arr1.getCapacity() << "]" << endl;
    //arr1.extend(100000);
    arr1.shuffleArr();

    double time = arr1.trackSelectionSort();
    cout << "Selection Sort Time: " << time << endl;
    //arr1.printArr();
    arr1.shuffleArr();

    time = arr1.trackInsertionSort();
    cout << "Insertion Sort Time: " << time << endl;
    //arr1.printArr();
    arr1.shuffleArr();

    time = arr1.trackBubbleSort();
    cout << "Bubble Sort Time: " << time << endl;
    //arr1.printArr();
    arr1.shuffleArr(); 

    time = arr1.trackQuickSort();
    cout << "Quick Sort Time: " << time << endl;

    arr1.shuffleArr();

    time = arr1.trackMergeSort();
    cout << "Merge Sort Time: " << time << endl;

    cout << "In Main: Testing sortJect via Nearly Sorted Array[" << arr1.getCapacity() << "]" << endl;

    arr1.nearlySorted();
    cout << "Selection Sort Time: " << time << endl;
    //arr1.printArr();
    arr1.nearlySorted();

    time = arr1.trackInsertionSort();
    cout << "Insertion Sort Time: " << time << endl;
    //arr1.printArr();
    arr1.nearlySorted();

    time = arr1.trackBubbleSort();
    cout << "Bubble Sort Time: " << time << endl;
    //arr1.printArr();
    arr1.nearlySorted(); 

    time = arr1.trackQuickSort();
    cout << "Quick Sort Time: " << time << endl;

    arr1.nearlySorted();

    time = arr1.trackMergeSort();
    cout << "Merge Sort Time: " << time << endl;

    cout << "In Main: Testing sortJect via Sorted Array[" << arr1.getCapacity() << "]" << endl;


    cout << "Selection Sort Time: " << time << endl;
    //arr1.printArr();
  

    time = arr1.trackInsertionSort();
    cout << "Insertion Sort Time: " << time << endl;
    //arr1.printArr();
   

    time = arr1.trackBubbleSort();
    cout << "Bubble Sort Time: " << time << endl;
    //arr1.printArr();
   

    time = arr1.trackQuickSort();
    cout << "Quick Sort Time: " << time << endl;


    time = arr1.trackMergeSort();
    cout << "Merge Sort Time: " << time << endl;

    return 0;
}