#include "sortJect.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){ //Some Demonstrated Use of the Class "sortJect"

    cout << "In Main: Testing sortJect..." << endl;

    sortJect arr1(10000); //Array Size 10000
    arr1.extend(50000);
    
    arr1.shuffleArr();

    double time = arr1.trackSelectionSort();
    cout << "Selection Sort Time: " << time << endl;

    arr1.shuffleArr();

    time = arr1.trackInsertionSort();
    cout << "Insertion Sort Time: " << time << endl;
    
    arr1.shuffleArr();

    time = arr1.trackBubbleSort();
    cout << "Bubble Sort Time: " << time << endl;

    arr1.shuffleArr();

    time = arr1.trackQuickSort();
    cout << "Quick Sort Time: " << time << endl;

    arr1.shuffleArr();

    time = arr1.trackMergeSort();
    cout << "Merge Sort Time: " << time << endl;

    return 0;
}