struct node {
    int data;
    node *next;

};
typedef node* Pnode;
struct set {
    Pnode H;
    stack_int();
    ~stack_int();
    void nhap(&set);
    void xuat(set);
    void them(int, set);
    set giao(set, set);
    set hieu(set, set);
};
set::set() {
    H = NULL;
}
set::~set() {
    while(H != NULL) {
        Pnode p;
        p = H;
        H = H -> next;
        delete p;

    }
}
void them(int x, set& A) {
    Pnode p;
    p = new node
    p -> data = x;
    p -> next = A.H;
    A.H = p;
}
void nhap(int x, set A, set B) 
void giao(set A, set B) {
    set C;
    Pnode p;
    p = A.H;
    while (p != NULL)
    {
        if(thuoc(p->data, B))
        them(p->data,R);

    }
    if (p = NULL)
}
set_int hop(set_int A, set_int B) {
    set_int R;
    Pnode p;
    p = A.H;
    while (p != NULL) {
        them(p->data,R)
        p = p->next;
    }
    p = B.H;
    while(p != NULL) {
        if (!thuoc(p->data,R))
            them(p->data,R);
            p = p -> next;
    }
    return R;
}
void main()
{
    set A,B,C;
    nhap(A);
    nhap(B);
    C = giao(A,B);
    xuat(C)
}