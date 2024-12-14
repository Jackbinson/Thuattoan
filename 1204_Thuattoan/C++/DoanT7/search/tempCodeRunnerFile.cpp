#include<iostream>
using namespace std;
#include <chrono>
using namespace std::chrono;
/*InterPolation_search là một sự cải tiến của tìm kiếm nhị phân Binary Search về phần:
-Tốc độ tìm kiếm được tối ưu rất cao
-Xu hướng tiến đến gần vị trí, giá trị tìm kiếm*/
int InterPolationSearch(int a[], int left, int right, int length, int queue) {
    while(left <= right && queue >= a[left] && queue <= a[right])
    {
        double val1 = (double) (queue - a[left]) / (a[right] - a[left]);
        int val2 = (right-left);
        int search = left + val1*val2;
        if (a[search] == queue)
            return search;
        if (a[search] < queue)
            left = search+1;
        else
            right = search - 1;
    }
    return -1;
}
int main() {
    int a[] = {10,12,16,18,20,22,55,35,72,47};
    int length = sizeof(a)/sizeof(*a);
    int queue;
    cout << "Type a number to find a value: ";
    cin >> queue;
     // Ghi lại thời gian kết thúc
        auto end = high_resolution_clock::now();
        auto start = high_resolution_clock::now();
        // Tính toán thời gian trôi qua
        auto duration = duration_cast<microseconds>(end - start);
    int index = InterPolationSearch(a,0,length-1,length,queue);
    if (index != -1)
        cout << "Found the number" << queue << "at" << index;
    else 
        cout << "not found" << queue << "in the list";
    cout << " " << endl;
    cout << "Time taken for the search: " << duration.count() << " microseconds" << endl;

}