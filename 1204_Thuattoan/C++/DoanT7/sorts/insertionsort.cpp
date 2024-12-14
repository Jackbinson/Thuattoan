#include<iostream>
using namespace std;
#include <chrono>
using namespace std::chrono;

void insertion_sort(int a[], int length) {
    for (int i = 1; i < length; i++) {
        int refvalue = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > refvalue) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = refvalue;
    }
}

int main() {
    int a[] = {64, 20, 40, 10, 60, 50};
    int length = sizeof(a) / sizeof(*a);

    cout << "The array before insertion sort:" << endl;
    for (int i = 0; i < length; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    insertion_sort(a, length);

    cout << "The array after insertion sort:" << endl;
    for (int i = 0; i < length; i++) {
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