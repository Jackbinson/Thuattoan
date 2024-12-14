#include <iostream>
#include <vector>
#include <algorithm> // std::binary_search
#include <chrono>    // std::chrono
#include <iomanip>   // std::setprecision

using namespace std;

// Hàm thực hiện tìm kiếm tam phân
int timKiemTamPhan(vector<int>& arr, int left, int right, int target) {
    if (right >= left) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == target) {
            return mid1;
        }
        if (arr[mid2] == target) {
            return mid2;
        }

        if (target < arr[mid1]) {
            return timKiemTamPhan(arr, left, mid1 - 1, target);
        } else if (target > arr[mid2]) {
            return timKiemTamPhan(arr, mid2 + 1, right, target);
        } else {
            return timKiemTamPhan(arr, mid1 + 1, mid2 - 1, target);
        }
    }
    return -1;
}

int main() {
    const int n = 1000000; // Tạo mảng với 1 triệu phần tử
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1;
    }

    int target = 999999; // Phần tử cần tìm
    const int numIterations = 1000; // Số lần lặp lại

    // Biến lưu kết quả tìm kiếm
    int ketQuaTamPhan;
    bool ketQuaNhiPhan;

    // Đo thời gian cho tìm kiếm tam phân
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < numIterations; ++i) {
        ketQuaTamPhan = timKiemTamPhan(arr, 0, n - 1, target);
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> durationTamPhan = end - start;
    double avgDurationTamPhan = durationTamPhan.count() / numIterations;

    // Đo thời gian cho tìm kiếm nhị phân
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < numIterations; ++i) {
        ketQuaNhiPhan = binary_search(arr.begin(), arr.end(), target);
    }
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> durationNhiPhan = end - start;
    double avgDurationNhiPhan = durationNhiPhan.count() / numIterations;

    // In kết quả
    cout << fixed << setprecision(9);
    cout << "Tìm kiếm tam phân:\n";
    if (ketQuaTamPhan != -1) {
        cout << "Phần tử được tìm thấy tại chỉ số " << ketQuaTamPhan << endl;
    } else {
        cout << "Không tìm thấy phần tử\n";
    }
    cout << "Thời gian chạy trung bình: " << avgDurationTamPhan << " giây\n";

    cout << "\nTìm kiếm nhị phân:\n";
    if (ketQuaNhiPhan) {
        cout << "Phần tử được tìm thấy\n";
    } else {
        cout << "Không tìm thấy phần tử\n";
    }
    cout << "Thời gian chạy trung bình: " << avgDurationNhiPhan << " giây\n";

    return 0;
}