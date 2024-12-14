#include <iostream>
using namespace std;
void BubbleSort(int arr[],int arrSize) {
    //Flag for swapping element
    bool isSwapped;
    //The value will be decreased everytime one element has been sorted
    int unsortedElements = arrSize;
    do {
        //If there's at least 2 elements are swapped, it'll be true
        isSwapped = false;
        //Iterate through the array's element
        for (int i = 0; i < unsortedElements-1;++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i],arr[i+1]);
                isSwapped = true;
            }
        }
        //After iteration, the last element has been sorted, so it'll be ignored in the nmexxt iteration
        --unsortedElements;
    }
    while (isSwapped);
 
    
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
    BubbleSort(arr, arrSize);

    // Display the sorted array
    cout << "Sorted array: " << endl;
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
