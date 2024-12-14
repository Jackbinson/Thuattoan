struct node {
    int data;
    node *next;
};

typedef node* Pnode;

struct set {
    Pnode H;
    set() { H = NULL; }
    ~set() {
        while(H != NULL) {
            Pnode p = H;
            H = H->next;
            delete p;
        }
    }
    void them(int, set&);
    bool thuoc(int, set);
    void nhap(set&);
    void xuat(set);
    set giao(set, set);
};

void set::them(int x, set& A) {
    Pnode p = new node;
    p->data = x;
    p->next = A.H;
    A.H = p;
}

bool set::thuoc(int x, set A) {
    Pnode p = A.H;
    while (p != NULL) {
        if (p->data == x) return true;
        p = p->next;
    }
    return false;
}

set set::giao(set A, set B) {
    set C;
    Pnode p = A.H;
    while (p != NULL) {
        if (thuoc(p->data, B)) {
            them(p->data, C);
        }
        p = p->next;
    }
    return C;
}

void set::nhap(set& A) {
    int x;
    while (cin >> x) { // Assuming input until a non-integer
        them(x, A);
    }
}

void set::xuat(set A) {
    Pnode p = A.H;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    set A, B, C;
    cout << "Enter elements for set A (non-integer to stop): ";
    A.nhap(A);
    cout << "Enter elements for set B (non-integer to stop): ";
    B.nhap(B);
    C = A.giao(A, B);
    cout << "Intersection of sets A and B: ";
    C.xuat(C);
    return 0;
}