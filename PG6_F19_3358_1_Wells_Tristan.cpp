// Serial Number : 72 & 75
//
// Author : Tristan Wells & Connor Widder
// Due Date : 11 - 20 - 19
// Programming Assignment Number 6
//
// Fall 2019 - CS 3358 - 1
//
// Instructor: Husain Gholoom.
//
// "SUMMARY"

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void return20(char arr[], int );
void search80(char arr[], int );
void selectionSort(char arr[], int );

int main(){

    srand(time(0)); //random number generator
    int sizeOfArray; //size of the array

    cout << "Enter the size of the array: ";
    cin >> sizeOfArray; //user inputs size of array
    cout << endl << endl;

    char myArray[sizeOfArray];
    cout << "The generated array is : ";
    for (int i = 0; i < sizeOfArray; i++){ //iterates and displays array
        myArray[i] = 'a' + rand() % 94 + 33;
    }
    return20(myArray, sizeOfArray);
    cout << endl << endl;
    search80(myArray, sizeOfArray);
    cout << endl << endl;
    selectionSort(myArray, sizeOfArray);

    return 0;
}

void return20(char arr[], int arraySize){

    int i = 0;

    if(arraySize > 20){

        while (i < 20){
        cout << arr[i] << " ";
        i++;
        }
    }
    else if(arraySize < 20){
        for (i = 0; i < arraySize; i++){
            cout << arr[i] << " ";
        }
    }
}

void search80(char arr[], int arraySize){
    int count = 0;

    for (int i = 0; i < arraySize; i++){
        if (arr[i] == 80)
            cout << "Comparisions: -> " << i;
    }
}

void selectionSort(char arr[], int arraySize){

    char temp;

    for(int i = 0; i < arraySize - 1; i++){
        for(int j = i+1; j < arraySize; j++){
            if(arr[j] < arr[i]){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
