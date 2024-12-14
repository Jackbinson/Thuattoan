#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

void bubble_sort(int a[], int length) {
    bool swapped;
    for (int i = 0; i < length - 1; i++) {
        swapped = false;
        for (int j = 0; j < length - 1 - i; j++) {
            if (a[j] > a[j + 1]) {  // Change to ascending order
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;  // No swap means the array is already sorted
        }
    }
}

int main() {
    cout << "The numbers before sorting: " << endl;
    int a[] = {1000000, 2000000, 3000000, 7000000, 8000000,100000};
    int length = sizeof(a) / sizeof(*a);

    for (int i = 0; i < length; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    bubble_sort(a, length);

    cout << "The numbers after sorting: " << endl;
    for (int i = 0; i < length; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    auto end = high_resolution_clock::now();
    auto start = high_resolution_clock::now();
        // Tính toán thời gian trôi qua
    auto duration = duration_cast<microseconds>(end - start);
    cout << " " << endl;
    cout << "Time taken for the search: " << duration.count() << " microseconds" << endl;
    return 0;
}