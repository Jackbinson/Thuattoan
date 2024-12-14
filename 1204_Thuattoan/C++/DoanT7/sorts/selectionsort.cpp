#include<iostream>
using namespace std;
#include <chrono>
using namespace std::chrono;
void selection_sort(int a[], int length) {
    for (int i = 0; i < length - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < length; j++) {
            if (a[j] < a[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            int temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
        }
    }
}

int main() {
    int a[] = {60, 30, 10, 50, 7,40,90,120,150};
    int length = sizeof(a) / sizeof(a[0]);

    cout << "The array before selection sort:" << endl;
    for (int i = 0; i < length; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    selection_sort(a, length);

    cout << "The array after selection sort:" << endl;
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