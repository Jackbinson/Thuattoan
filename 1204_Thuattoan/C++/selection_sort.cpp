/* Selection sort 
Suppose to sort in an ascending order.
Idea: 
1. Divivdee an input into 2 parts: sublist of items already sorted in the left side & sublist of item remaining to be sorted.
2. The lowest items will be in the leftmost position.
Alogorithm: 
1. Find the list index of the unsorted sublist & mark it as 'minIndex'. for instance, if the first sorting iteration, the index is 0.
2. Iterate through the elements of the unsorted subllist, starting at its firs element (the 1st time, it should be index 1 through n-1) & compare the current value 
element in this iteration with the 1st index of the unsorted sublist.
    2.1. If the value of the curfrent index is lower than the value of the 1st index, set the current index to 'Miniindex' (update miniIndex).
3. After finishing the unsorted elements iteration, swap each value of the 1st index of the unsorted sublist and the minidex.
4. Repeat step (1)-(2)-(3) until the unsorted sublist has only 1 item remaining*/
#include<iostream>
using namespace std;
void SelectionSort(int arr[], int arrSize) {
    // Variable to store the index of the minimum value in each iteration
    for (int i = 0; i < arrSize - 1; ++i) {
        int minIndex = i;  // Initialize minIndex to the current position
        
        // Iterate through the unsorted elements only
        for (int j = i + 1; j < arrSize; ++j) {
            // Set the new min value if the current element is smaller than the current min
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap the 1st unsorted element with the min value
        swap(arr[i], arr[minIndex]);
    }
}
int main() {
    cout << "Selection sort" << endl;
    // Initialize a new array
    int arr[] = {30, 15, 5, 10, 25, 20};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    // Display the initial array
    cout << "Initial array: " << endl;
    for (int i = 0; i < arrSize; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Selection sort
    SelectionSort(arr, arrSize);

    // Display the sorted array
    cout << "Sorted array: " << endl;
    for (int i = 0; i < arrSize; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}