#include <iostream> 
struct node {
    double data;
    node* next;
};
typedef node* Pnode;
void themdau(double x, Pnode& H)
{
    Pnode p;
    p = new node;
    p -> data = x;
    p -> next = H;
    H = p;
}

void themcuoi(double x, Pnode& H) {
    if (H == NULL) {
        themdau(x, H);
    } else {
        Pnode p = new node;
        p->data = x;
        p->next = NULL;

        Pnode q = H;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
}
double laydau(Pnode& H)
{
    Pnode p;
    double x;
    p = H;
    H = H ->next;
    
}    
double laycuoi(Pnode& H)
{
    if (H->next == NULL)
    return laydau(H);
    Pnode p;
    p = H;
    while (p-> next -> next != NULL)
    p = p-> next;
    double x;
    x = p-> next-> data;
    delete p-> next;
    p->next = NULL;
    return x;
}
Pnode timkiem(double x, Pnode H)
{
    Pnode p;
    p = H;
    while (p != NULL)
    {
        if (x == p -> data)
            return p;
        p = p-> next;
    }
}
void nhapDSLK(Pnode& H)
{
    double x;
    if (H != NULL)
        huyDSLK(H)
    cout << "Nhap cac so thuc (ket thuc boi 0): " << endl;
    cin << x;
    while (x != 0)
    {
        themdau(x, H);
        cin >> x;
    }
}
void huyDSLK(Pnode& H) {
    while (H !=NULL)
        laydau(H);
}