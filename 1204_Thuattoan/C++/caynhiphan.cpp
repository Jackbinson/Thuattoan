struct node {
    double data;
    node* left, * right;
};
typedef node* Pnode;
//Cho phép khai báo biến cho một cây
Pnode T;
//Gán giá trị cho T ban đầu là NULL (để ghi nhận là cây rỗng):
T = NULL;
//
double tong(Pnode T)
{
    double S = 0;
    if (T != NULL)
    S = T -> data + tong(T->left) + tong(T->right);
    return S;
}
//duyệt cây và xuất các phân tử ra màn hình
void xuat(Pnode T) {
    if (T != NULL) {
        cout << T->data << ""
        xuat(T->left);
    }
}
//Cây nhị phân tìm kiếm
//Cây nhị phân mà các phần tử được bố trí theo thứ tự từ nhỏ đến lớn (hoặc từ lớn xuống nhỏ) theo nghĩa là:
/*Các phần tử của cây con bên trái <node < Các phần tử của cây con bên phải.
    Hàm tìm kiếm trên cây nhị phân(bất kỳ)*/
Pnode timkiem(double x, Pnode T) {
    if (T == NULL) 
        return NULL;
    if (x == T->data)
        return T;
    Pnode p;
    p = timkiem(x, T->left);
    if (p != NULL)
        return p;
    else  
        return timkiem(x,T->right)
}
/*Hàm tìm kiếm trên cây nhị phân "nhị  phân tìm kiếm" */
Pnode timkiem_BST(double x, Pnode T)
{
    if (T == NULL)
        return NULL;
    if (x == T -> data)
        return T;
    if (x < T -> data)
        return timkiem_BST(x, T-> left);
    else
        return timkiem_BST(x, T ->right);
}
void them(double x, Pnode & T)
{
    if (T == NULL)
    {
        T = new node;
        T->data = x;
        T->left = T ->right = NULL;

    }
    else if (x < T -> data)
    them(x, T->left);
    else 
    them(x,T->right)
}