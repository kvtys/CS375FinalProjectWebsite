#pragma once

void swap(int arr[], int i, int j);
void selectionSort(int arr[], int size); // O(n^2)
void insertionSort(int arr[], int size); // O(n^2), can be O(n) in some cases
void bubbleSort(int arr[], int size);  //O(n^2), can be O(n) in some cases
int qPartition(int arr[], int low, int high); 
void quickSort(int arr[], int low, int high); //O(n^2) but usually O(nlogn)
void merge(int arr[], int low, int middle, int high);
void mergeSort(int arr[], int low, int high); //O(nlogn) guarantee
