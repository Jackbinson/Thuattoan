#include <iostream>
#include <chrono> // Thư viện để đo thời gian

using namespace std;
using namespace std::chrono; // Sử dụng namespace chrono để truy cập các loại thời gian

// Function to perform linear search
int linear_search(int a[], int length, int queue) {
    for (int i = 0; i < length; i++) {
        if (a[i] == queue) {
            return i; // Element found, return its index
        }
    }
    return -1; // Element not found, return -1
}

int main() {
    int a[] = {10, 50, 20, 70, 40, 20, 100, 30, 80, 150};
    int length = sizeof(a) / sizeof(*a);
    int queue;

    // Print the list
    cout << "List of numbers: ";
    for (int i = 0; i < length; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // Ghi lại thời gian bắt đầu
    auto start = high_resolution_clock::now();

    // Loop until the user enters a number that exists in the list
    while (true) {
        cout << "Type a number in the list to search: ";
        cin >> queue;
        int index = linear_search(a, length, queue);
        if (index != -1) {
            cout << "Number found at index: " << index << endl;
            break; // Exit the loop if the number is found
        } else {
            cout << "Number not found in the list. Please try again." << endl;
        }
    }

    // Ghi lại thời gian kết thúc
    auto end = high_resolution_clock::now();

    // Tính toán thời gian trôi qua
    auto duration = duration_cast<microseconds>(end - start);

    // In ra thời gian thực thi
    cout << "Time taken for the search: " << duration.count() << " microseconds" << endl;

    return 0;
}