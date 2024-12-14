#include<iostream>
#include<chrono> // Thư viện để tính thời gian

using namespace std;

/*InterPolation_search là một sự cải tiến của tìm kiếm nhị phân Binary Search về phần:
-Tốc độ tìm kiếm được tối ưu rất cao
-Xu hướng tiến đến gần vị trí, giá trị tìm kiếm*/
int InterPolationSearch(int a[], int left, int right, int length, int queue) {
    while(left <= right && queue >= a[left] && queue <= a[right])
    {
        double val1 = (double) (queue - a[left]) / (a[right] - a[left]); // Tỉ lệ khoảng cách từ giá trị tìm kiếm 'queue' đến giá trị left so với left tới right
        int val2 = (right-left); // Tính độ dài của left đến right
        int search = left + val1*val2; // Ước lượng của giá trị queue dựa trên tỷ lệ nội suy.
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
    int a[] = {10,12,16,18,20,22,35,47,55,72}; // Dãy phải được sắp xếp cho InterPolation Search
    int length = sizeof(a)/sizeof(*a);
    int queue;

    cout << "Type the number that needs to be found: ";
    cin >> queue;

    // Bắt đầu đếm thời gian
    auto start = chrono::high_resolution_clock::now();
    
    int index = InterPolationSearch(a,0,length-1,length,queue);

    // Kết thúc đếm thời gian
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    if (index != -1)
        cout << "Found " << queue << " at index " << index << endl;
    else 
        cout << "Not found " << queue << " inside array list" << endl;

    // Xuất thời gian đã thực hiện
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;

    return 0;
}