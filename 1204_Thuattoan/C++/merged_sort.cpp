/* Merge sort 
Suppose to sort in an ascending order
idea: 
    1. Divide the array into 2 subarrays until we have only sublists with onoly 2 elements.
    2. Sort then merge.
Algorithm:
    1. Divide the array into 2 parts.
    2. Sort each subarray them merge them.
    3. To sort each subarray, do step (1)-(2)
    */
#include<iostream>
using namespace std;
//Merge function: pass an array, a start, a middle & a end index. Is used when we have an array where each half part has been sorted.
void Merge(int arr[], int startIndex, int middleIndex, int endIndex) {
    //Numbers of elements that will be sorted from startIndex to endIndex
    int totalElements = endIndex - startIndex + 1;
    //Temporary array to store merged array
    int *tempArray = new int[totalElements];
    //Index of middle subarray 

    int leftIndex = startIndex;
    //Index of right subarray: arr[middleIndex+1....endIndex]
    int rightIndex = middleIndex + 1;
    //Index of merged array
    int mergedIndex = 0;
    //Merge the 2 subarrays
    while (leftIndex <= middleIndex && rightIndex <= endIndex) {
        if (arr[leftIndex] <= arr[rightIndex]) {
            //store the left subarray's element if it's lower than the right one
            tempArray[mergedIndex] = arr[leftIndex];
            //Go to next left subarray index
            ++leftIndex;
        } 
        else {
            //Store the right subarray's element if it's lower than the left one
            tempArray[mergedIndex] = arr[rightIndex];
            //Go to next right subarray index
            ++rightIndex;
        }
            //Go to next merged array index
            ++mergedIndex; }
        //if there're any remaining element in left subarray that is not stored to merged array yet.
        while (leftIndex <= middleIndex) {
            tempArray[mergedIndex] = arr[leftIndex];
        // go to next left subarray index;
        ++leftIndex;
        // go to next merged array index
        ++mergedIndex;
        }
        //if there're any remaining element in right subarray that is not stored to merged aray yet
        while (rightIndex <= endIndex) {
            tempArray[mergedIndex] = arr[rightIndex];
        // go to next right subarray index
        ++rightIndex;
        // g oto next merged array index
        ++ mergedIndex;
        }
        //now the merged array has been sorted.Copy element to the original array
        for (int i = 0; i < totalElements; ++i) {
            arr[startIndex + i] = tempArray[i];
        }
    }
