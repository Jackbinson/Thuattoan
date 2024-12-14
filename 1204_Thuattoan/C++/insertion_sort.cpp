/* Insertion sort 
supppoise to sort in an ascending order
Idea: 
    1. Divve the array into a sorted and unssorted sublists.
    2. Pick a reference item & insert into the correct position in the sorted list.
Algorithm:
    1. Pick a item as a reference.
    2. Go through the sorted sublist to find the correct position based on a comparison. 
    3. Repeat (1) - (2) until all the items are sorted. <=> itrate through all the array's elements.
*/
#include <iostream>
using namespace std;
void InsertionSort(int arr[], int arrSize) {
    // Iterate through all array elements
    for (int i = 1; i < arrSize; ++i) {
        // Set the current element as reference value
        int refValue = arr[i];
        // Variable to shift the element to the right position
        int j;
        // Iterate through the sorted elements to insert the refValue in the right position
        for (j = i - 1; j >= 0 && arr[j] > refValue; --j) {
            // If the value of the current index is greater than the refValue, move the current value to the right side
            arr[j + 1] = arr[j];
        }
        // Put the refValue in the current index (right position)
        arr[j + 1] = refValue;
    }
}

int main() {
    cout << "Insertion Sort" << endl;
    // Initialize a new array 
    int arr[] = {30, 10, 5, 15, 25, 20};
    int arrSize = sizeof(arr) / sizeof(arr[0]); //Dùng để tính bytes, int là 4 bytes và arr là 6 số bao gồm4
    // Display the initial array 
    cout << "Initial array: " << endl;
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sort the array
    InsertionSort(arr, arrSize);

    // Display the sorted array
    cout << "Sorted array: " << endl;
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}