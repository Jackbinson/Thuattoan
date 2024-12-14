/* Bài mới stacks
- It is an ordered group of homogenous itemss of elements.
- Elementss are added to and removed from the top of the stack (the most recently added  itemss are tat the top of the stack).
- The last element to be added is the first to be removed
LIFO: Last In, First out 
Example: A stack of cafeteria, a stack of pennies, a stack of shoe boxes, a stack of neatly folded shirts.
*/ 
//Ví dụ: cài đặt ngăn xếp các số nguyên (int) và test (dựa trên c)
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

typedef Node* Pnode;
struct stack_int {
    Pnode H;
    stack_int(); //Sử dụng để tự chạy khi đã khai báo cái biến từ các hàm khác 
    ~stack_int(); //Tự hủy bỏ những biến không còn hiệu lực
    void push(int);
    int pop();
    bool empty(); 
    int top();
} //Hàm sử dụng để khai báo biến, không cần phải gọi hàm 
stack_int::stack_int() {
    H = NULL;
}
stack_int::~stack_int()
{
    while (H != NULL) {
        Pnode p;
        p = H;
        H = H-> next;
        delete p;
    
    }
}
void stack_int::push(int x)
{
    Pnode p;
    p = new Node;
    p -> data = x;
    p -> next = H;
    H = p;
}
int stack_int::pop(){
    int x;
    Pnode p;
    x = H -> data;
    p = H;
    H = H->next;
    delete p;
    return x;
}
bool stack_int::empty() {
     if(H == NULL) 
        return true;
    return false;
}        
int stack_int::top() {
    return H -> data;
}
// void  main() {
//     Pnode St;
//     St = NULL;
//     cout << "Vui lòng nhập 10 số nguyên để đưa vào ngăn xếp: " << endl; 
//     for (int i = 0; i < 10; i++) {
//         int x;
//         cin >> x;
//         push(x, St);
//     }
//     cout << "Câc phân lấy từ ngăn xếp: " << endl;
//     while (!empty(St)) {
//         cout << pop(St) << " ";

//     }
//     cout << endl; //Ngăn xếp St khác rỗng
// }
//Chú ý thêm thì phải chú ý còn chỗ thay không
// Áp dụng xóa phân tử và trả lại phần tử.
//Sử dụng lệnh if H == NULL để kiểm tra hệ thống
//Ngăn xếp của nguyên tử cấu trúc đơn

int main() {
    stack_int St;
    cout << "Vui long nhap 10 so vao ngan xep phan tu: " << endl; 
    for (int i = 0; i < 10; i++) {
        int x;
        cin >> x;
        St.push(x);
    }
    cout << "Cac phan tu lay ngau nhien: " << endl;
    while (!St.empty()) {
        cout << St.pop() << " ";
    }
    cout << endl; //Ngăn xếp St khác rỗng

} 