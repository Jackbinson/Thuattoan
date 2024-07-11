/* What is a queue (Hàng đợi`)
it is an ordered group of homogeneous items of elements.
Queues have two ends:
-Element are added at one end.
-Element are removed from the other end
The element added first is also removed first
(FIFO: First in, First out).*/
// Sử dụng DSLK đơnn để chứa các phần tử của hàng đợi
// Xử lý thêm phần tử: thêm cuối
//Xử lấy ra phần tử: lấy đầu
#include<iostream>
  using namespace std;
  
  struct node {
    int data;
    node* next;
};
typedef node* Pnode;
struct queue_int {
    Pnode H,T;
    queue_int();
    ~queue_int();
    void add(int);
    int get();
    bool empty();
};

queue_int::queue_int() {
    H = T = NULL;

}
queue_int::~queue_int() {
    while (H != NULL)
    {
        Pnode p;
        p = H;
        H = H-> next;
        delete p;
    }
}
void queue_int::add(int x)
{
    if (H == NULL)
    {
        H = T = new node; //Có một node duy nhất 
        H -> data = x; H -> next = NULL;
    }
    else
    {
        T -> next = new node;
        T = T -> next;
        T -> data = x;
        T -> next = NULL;
    }
    
}