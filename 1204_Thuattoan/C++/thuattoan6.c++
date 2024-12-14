#include <iostream>
using namespace std;

struct node {
    int data;
    node *left, *right;
};

typedef node *Pnode;

// Hàm tính tổng các giá trị trong cây nhị phân
double tong(Pnode T) {
    double S = 0;
    if (T != NULL) {
        S = T->data + tong(T->left) + tong(T->right);
    }
    return S;
}

// Hàm duyệt cây và xuất các phần tử ra màn hình (preorder)
void xuat(Pnode T) {
    if (T != NULL) {
        cout << T->data << " ";  // Thay đổi "" thành " " để dễ đọc
        xuat(T->left);
        xuat(T->right);
    }
}

// Hàm tìm kiếm giá trị x trong cây nhị phân (không phải BST)
Pnode timkiem(double x, Pnode T) {
    if (T == NULL)
        return NULL;
    if (x == T->data)
        return T;
    Pnode p = timkiem(x, T->left);
    if (p != NULL)
        return p;
    else 
        return timkiem(x, T->right);
}

// Hàm tìm kiếm giá trị x trong cây nhị phân tìm kiếm (BST)
Pnode timkiem_BST(double x, Pnode T) {
    if (T == NULL)
        return NULL;
    if (x == T->data)
        return T;
    if (x < T->data)
        return timkiem_BST(x, T->left);
    else
        return timkiem_BST(x, T->right);
}

// Hàm thêm giá trị x vào cây nhị phân tìm kiếm (BST)
void them(double x, Pnode& T) {
    if (T == NULL) {
        T = new node;
        T->data = x;
        T->left = T->right = NULL;
    } else if (x < T->data) {
        them(x, T->left);
    } else {
        them(x, T->right);
    }
}

int main() {
    Pnode root = NULL;

    // Thêm các phần tử vào cây BST
    them(10, root);
    them(5, root);
    them(20, root);
    them(3, root);
    them(7, root);
    them(15, root);
    them(25, root);

    // Xuất các phần tử của cây
    cout << "Cay nhan duoc duyet theo preorder: ";
    xuat(root);
    cout << endl;

    // Tinh tong cac phan tu trong cay
    cout << "Tong cac phan tu trong cay: " << tong(root) << endl;

    // Tim kiem mot phan tu trong cay
    double x = 7;
    Pnode foundNode = timkiem_BST(x, root);
    if (foundNode != NULL) {
        cout << "Tim thay " << x << " trong cay." << endl;
    } else {
        cout << "Khong tim thay " << x << " trong cay." << endl;
    }

    return 0;
}