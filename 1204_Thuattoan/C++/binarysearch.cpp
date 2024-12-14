/*Binary Search 
Assumption: Given a sorted aray. Use-case: in ascending order*/
#include <iostream>
using namespace std;
int BinarySearch(int arr[], int startINdex, int endIndex, int val) {
    //Only search if the end index is higher than or equals to the start index
    if (startINdex <= endIndex) {
        int middleINdex = startINdex + (endIndex-startINdex)/2;
    //If the middle INdex's value is searched value than return
    if (arr[middleINdex] == val) return middleINdex;
    else if (arr[middleINdex] > val ) //search left subarray arr[startIndex ... middleIndex - 1 ]
        return BinarySearch(arr, startINdex, middleINdex-1,val);
    else //Search right subarray arr[middleINdex+1...endINdex]
        return BinarySearch(arr,middleINdex+1,endIndex,val);
    }

//In case no any value found
    return -1;
}
int main() {
    cout << "Binary Search" << endl;
    //Initialize a new array
    int arr[] = {5,10,15,20,25,30,35,40,45,50};
    int arrSize = sizeof(arr)/sizeof(*arr);
    //Define value to be searched 
    int searchedValue = 12;
    //Find the searched value using binary search
    int i = BinarySearch(arr, 0, arrSize-1,searchedValue);
    if (i != -1) cout << searchedValue << "is found in index" << i << endl;
    else cout << "Could not find value" << searchedValue << endl;
    return 0;
}