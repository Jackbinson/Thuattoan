/*Ternary Search
1. Divide an input array into 3 subarrays.
2. Pick 2 indexes: middleLeftIndex, middleRightIndex based on 1st and the last indexes of the input array.
*/

#include <iostream>

using namespace std;

int TernarySearch(int arr[], int startIndex, int endIndex, int val) {
    // Only search if the end index is higher than or equals to the start index
    if (startIndex <= endIndex) {
      // Find index of area of the first third
      int middleLeftIndex = startIndex + (endIndex-startIndex) / 3;
      // Find index of area of the last third
      int middleRightIndex = middleLeftIndex + (endIndex-startIndex) / 3;

      // If value is at middleLeftIndex then return
      if(arr[middleLeftIndex] == val) return middleLeftIndex;
      else if(arr[middleRightIndex] == val) // If val is at middleRightIndex then return
        return middleRightIndex;
      else if(arr[middleLeftIndex] > val) // If val is at the area of the 1st third
        return TernarySearch(arr, startIndex, middleLeftIndex-1, val);
      else if (arr[middleRightIndex] < val) // If val is at the area of the last third
        return TernarySearch(arr, middleRightIndex+1, endIndex, val);
      else // If val is at the area between middleLeftIndex and middleRightIndex
        return TernarySearch(arr, middleLeftIndex+1, middleRightIndex-1, val);
    }

    // In case no any value found
    return -1;
}

int main(){
    cout << "Ternary Search" << endl;

    // Initialize a new arr
    int arr[] = {5, 10, 15, 20 ,25, 30,35, 40, 45 ,50, 55, 60, 65, 70, 75};
    int arrSize = sizeof(arr) / sizeof(*arr);
    // Define value to be searched
    int searchedValue = 15;

    // Find the searched value using Binary Search
    int i = TernarySearch(arr, 0, arrSize-1, searchedValue);
    
    // Announce results
    if (i!= -1) cout << searchedValue << " is found in index " << i << endl;
    else cout << "Could not find value " << searchedValue << endl;

    return 0;
}