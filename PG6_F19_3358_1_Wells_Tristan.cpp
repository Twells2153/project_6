// Serial Number : 72, 75
//
// Author : Tristan Wells, Connor Widder
// Due Date : 11 - 20 - 19
// Programming Assignment Number 6
//
// Fall 2019 - CS 3358 - 1
//
// Instructor: Husain Gholoom.
//
// "SUMMARY"

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
using namespace std;

void copyArray(char arr[], char arr2[], int);
void return20(char arr[], int );
void search80(char arr[], int );
void selectionSort(char arr[], int );
void insertionSort(char arr[], int );
int quickSort_Middle(char arr[], int, int);
int quickSort_Front(char arr[], int, int);
int quickSort_Back(char arr[], int, int);


//can use c.time or time.h

int main(){
    srand(time(0)); //random number generator
    int sizeOfArray; //size of the array
    
    
    cout << "Enter the size of the array: ";
    cin >> sizeOfArray; //user inputs size of array
    cout << endl;
    
    char myArray[sizeOfArray];
    cout << "The generated array is : ";
    for (int i = 0; i < sizeOfArray; i++){ //iterates and displays array
        myArray[i] = rand() % 94 + 33;      //*Characters, not just numbers*
    }
    char tempArray[sizeOfArray];
    
    //Setup timeing
    clock_t t, t_seq, t_sel, t_inser, t_qsM, t_qsF, t_qsB;
    t = clock();    //Starting time
        
    copyArray(myArray, tempArray, sizeOfArray);
    return20(tempArray, sizeOfArray);
    cout << endl << endl;
    
    
    //----Sequential Search----
    cout << "Sequential Search:" << endl;
    t_seq = clock();
    cout << "Searching for 80" << endl;
    copyArray(myArray, tempArray, sizeOfArray);
    search80(tempArray, sizeOfArray);
    cout << "Start Time: " << ((float)t_seq)/CLOCKS_PER_SEC<< "s" << endl;
    cout << "End Time: " << ((float)clock())/CLOCKS_PER_SEC<< "s" << endl;
    t_seq = clock() - t_seq;
    cout << "Actual CPU Clock time: " << ((float)t_seq)/CLOCKS_PER_SEC<< "s" << endl;
    cout << endl << endl;
    
    
    //----Selection Sort----
    cout << "Selection Sort:" << endl;
    copyArray(myArray, tempArray, sizeOfArray);
    t_sel = clock();
    selectionSort(tempArray, sizeOfArray);
    cout << "Start Time: " << ((float)t_sel)/CLOCKS_PER_SEC<< "s" << endl;
    cout << "End Time: " << ((float)clock())/CLOCKS_PER_SEC<< "s" << endl;
    t_sel = clock() - t_sel;
    cout << "Actual CPU Clock time: " << ((float)t_sel)/CLOCKS_PER_SEC<< "s" << endl;
    cout << endl << endl;
    
    
    //----Insertion Sort----
    cout << "Insertion Sort:" << endl;
    copyArray(myArray, tempArray, sizeOfArray);
    t_inser = clock();
    insertionSort(tempArray, sizeOfArray);
    cout << "Start Time: " << ((float)t_inser)/CLOCKS_PER_SEC<< "s" << endl;
    cout << "End Time: " << ((float)clock())/CLOCKS_PER_SEC<< "s" << endl;
    t_inser = clock() - t_inser;
    cout << "Actual CPU Clock time: " << ((float)t_inser)/CLOCKS_PER_SEC<< "s" << endl;
    cout << endl << endl;
    
    
    //----Quick Sort----
    //Pivoit = next to middle element
    cout << "Quick Sort - Next to middle element as a pivoit:" << endl;
    copyArray(myArray, tempArray, sizeOfArray);
    t_qsM = clock();
    cout << "Total Number of Recursive Calls: " << quickSort_Middle(tempArray, 0, sizeOfArray) << endl;    //Sort using next to middle value as pivot
    cout << "Start Time: " << ((float)t_qsM)/CLOCKS_PER_SEC<< "s" << endl;
    cout << "End Time: " << ((float)clock())/CLOCKS_PER_SEC<< "s" << endl;
    t_qsM = clock() - t_qsM;
    cout << "Actual CPU Clock time: " << ((float)t_qsM)/CLOCKS_PER_SEC<< "s" << endl;
    cout << endl << endl;
    
    //Pivoit = front element
    cout << "Quick Sort - Front element as a pivoit:" << endl;
    copyArray(myArray, tempArray, sizeOfArray);
    t_qsF = clock();
    cout << "Total Number of Recursive Calls: " << quickSort_Front(tempArray, 0, sizeOfArray) << endl;    //Sort using first value as pivot
    cout << "Start Time: " << ((float)t_qsF)/CLOCKS_PER_SEC<< "s" << endl;
    cout << "End Time: " << ((float)clock())/CLOCKS_PER_SEC<< "s" << endl;
    t_qsF = clock() - t_qsF;
    cout << "Actual CPU Clock time: " << ((float)t_qsF)/CLOCKS_PER_SEC<< "s" << endl;
    cout << endl << endl;
    
    //Pivoit = back element
    cout << "Quick Sort - Back element as a pivoit:" << endl;
    copyArray(myArray, tempArray, sizeOfArray);
    t_qsB = clock();
    cout << "Total Number of Recursive Calls: " << quickSort_Back(tempArray, 0, sizeOfArray) << endl;    //Sort using last value as pivot
    cout << "Start Time: " << ((float)t_qsB)/CLOCKS_PER_SEC<< "s" << endl;
    cout << "End Time: " << ((float)clock())/CLOCKS_PER_SEC<< "s" << endl;
    t_qsB = clock() - t_qsB;
    cout << "Actual CPU Clock time: " << ((float)t_qsB)/CLOCKS_PER_SEC<< "s" << endl;
    cout << endl << endl;
    
    
    cout << "11 - 20 - 2019" << endl;
    cout << "Benchmark Algorithm Implemented by :" << endl;
    cout << "Tristen Wells, Connor Widder" << endl;
    
    return 0;
}

void copyArray(char arr1[], char arr2[], int arraySize){
    for (int i = 0; i < arraySize; i++){
        arr2[i] = arr1[i];
    }
}

void return20(char arr[], int arraySize){
    
    int i = 0;
    
    if(arraySize > 20){
        
        while (i < 20){
            cout << arr[i] << " ";
            i++;
        }
    }
    else {
        for (i = 0; i < arraySize; i++){
            cout << arr[i] << " ";
        }
    }
}

void search80(char arr[], int arraySize){
    
    int comparisons = 0;
    
    for (int i = 0; i < arraySize; i++){
        if (arr[i] == 80){
            comparisons++;
            cout << "80 was not found.";
            cout << "Total Number of Comparisons: " << comparisons << endl;   //Display comparisons if found
            return;
        }
        comparisons++;
    }
    cout << "80 was not found." << endl;
    cout << "Total Number of Comparisons: " << comparisons << endl;           //Display comparisons if not found
}

void selectionSort(char arr[], int arraySize){
    
    char temp;
    int comparisons = 0;
    
    for(int i = 0; i < arraySize - 1; i++){
        for(int j = i+1; j < arraySize; j++){
            if(arr[j] < arr[i]){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                comparisons ++;
            }
        }
    }
    cout << "Total Number of Comparisons: " << comparisons << endl;
}

void insertionSort(char arr[], int arraySize){
    
    char temp;
    int j;
    int comparisons = 0;
    
    for (int i = 1; i < arraySize; i++){
        temp = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j = j - 1;
            comparisons++;
        }
        arr[j + 1] = temp;
        //comparisons++;
    }
    cout << "Total Number of Comparisons: " << comparisons << endl;
}

int quickSort_Middle(char arr[], int left, int right){
    int count = 0;
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
    
    // partition
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {           //Swap values
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
    
    // recursion
    if (left < j){
        count++;
        count += quickSort_Middle(arr, left, j);
        
    }
    if (i < right){
        count++;
        count += quickSort_Middle(arr, i, right);
    }
    return count;
}

int quickSort_Front(char arr[], int left, int right){
    int count = 0;
    int i = left, j = right;
    int tmp;
    int pivot = arr[left];
    
    // partition
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {           //Swap values
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
    
    // recursion
    if (left < j){
        count++;
        count += quickSort_Front(arr, left, j);
        
    }
    if (i < right){
        count++;
        count += quickSort_Front(arr, i, right);
    }
    return count;
}

int quickSort_Back(char arr[], int left, int right){
    int count = 0;
    int i = left, j = right;
    int tmp;
    int pivot = arr[right];
    
    // partition
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {           //Swap values
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
    
    // recursion
    if (left < j){
        count++;
        count += quickSort_Back(arr, left, j);
        
    }
    if (i < right){
        count++;
        count += quickSort_Back(arr, i, right);
    }
    return count;
}

