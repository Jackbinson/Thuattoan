#include<iostream>
using namespace std;

// Function to perform binary search
int binary_search(int a[], int low, int high, int x) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (a[mid] == x) return mid;
        if (a[mid] > x) return binary_search(a, low, mid - 1, x);
        else return binary_search(a, mid + 1, high, x);
    }
    return -1; // Element not found
}

int main() {
    int a[] = {30, 10, 50, 70, 100, 90, 20,40,120,150};
    int length = sizeof(a) / sizeof(*a);
    
    // Print the array
    cout << "Array elements: ";
    for (int i = 0; i < length; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // Define the element to search for
    int x = 100;

    // Perform binary search
    int result = binary_search(a, 0, length - 1, x);
    
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}