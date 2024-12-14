typedef int dinh;
struct tapdinh {
    int n;
    dinh v[30];
};
struct canh {
    dinh x,y;
}
struct tapcanh {
    int n; //số cạnh
    canh e[30 * 29/ 2]; //Khả năng chứa số lượng tối đa
};
struct dothi {
    tapdinh V;
    tapdinh E;
};
void nhap(dothi&);
void xuat(dothi);

void nhap(dothi& G) {
    //Nhập tập định
    cout << "Số đỉnh: "; cin >> G.V.n;
    
}