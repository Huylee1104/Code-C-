#include <bits/stdc++.h>
using namespace std;

// khai báo cấu trúc 1 node
struct node
{
    int data; // dữ liệu node lưu trữ
    struct node *pLeft; // node liên kết bên trái
    struct node *pRight;// node liên kế bên phải
};
typedef struct node NODE;
typedef NODE* TREE; 

// khởi tạo cây
void KhoiTaoCay(TREE &t){
    t = NULL; // cây rộng chưa có phần tử
}

// hàm thêm phần tử vào cây nhị phân
void ThemNode(TREE &t, int x){
    if (t == NULL){
        NODE *p = new NODE; // khởi tạo 1 node thêm vào cây
        p->data = x; // thêm phần tử x vào data và 2 nhánh sẽ rỗng
        p->pLeft = NULL;
        p->pRight = NULL; 
        t = p; // node p là node gốc <=> x chính là node gốc
    }
    else{
        if (x < t->data){ // Nếu phần tử thêm vào nhỏ hơn node gốc
            ThemNode(t->pLeft, x);// duyệt qua bên trái để thêm phần tử x
            // bản chất chỗ này là t->pLeft sẽ trở thành node gốc tại chính nó khi gọi đệ quy
        }
        else if (x > t->data){
            ThemNode(t->pRight, x); // duyệt qua bên phải để thêm phần tử x
        }
    }
}

// hàm xuất cây nhi phân theo NLR
void DuyetNLR(TREE t){
    // nếu cây còn phần tử thì tiếp tục duyệt
    if (t != NULL){
        cout << t->data << " "; // Xuất dữ liệu trong node
        DuyetNLR (t->pLeft); // duyệt qua trái
        // bản chất chỗ này là khi gọi hàm và truyền t->pLeft thì thành t->data ở lần gọi này
        DuyetNLR (t->pRight); // duyệt qua phải
    }
}

bool KiemTraNguyenTo(int x){
    if (x < 2){ // Nếu x < 2 thì không phải số nguyên tố
        return false;
    }
    else{
        for(int i =1; i <= sqrt(x); i++){
            if (x % i == 0){ return false;} // nếu từ 1 đến căn x có số được x chia hết thì không phải số nguyên tố
        }
        return true;
    }
}

int DemSoLuongSoNguyenTo(TREE t, int &dem){
    if ( t != NULL){
        if (KiemTraNguyenTo(t->data) == true){
            dem++;
        }
        DemSoLuongSoNguyenTo(t->pLeft, dem);
        DemSoLuongSoNguyenTo(t->pRight, dem);
    }
    return dem;
}

// tìm kiếm một node trong cây nhị phân
int TimKiem(TREE t, int x){
    if (t == NULL){
        cout << "Cay khong ton tai !";
    }
    else{
        if (t->data == x){
            cout << "Tim thay trong cay node: ";
            return x;
        }
        else if (x > t->data){
            TimKiem(t->pRight, x);
        }
        else if (x < t->data){
            TimKiem(t->pLeft, x);
        }
    }
    return 0;
}

// In node có 2 con
void InNode(TREE &t){
    if (t != NULL){
        /* In node 2 con: pleft và pright khác NULL
        In node có 1 con: pleft hoặc pright có 1 bên NULL
        In node lá: pleft và pright NULL
        */
        if (t->pLeft != NULL && t->pRight != NULL){
            cout << t->data << " ";
        }
        InNode(t->pLeft);
        InNode(t->pRight);
    }
}

// Tìm node lớn nhất
int TimMax(TREE &t){
    if (t->pRight == NULL){ // Do node bên phải luôn lớn nhất, trường hợp tìm min thì ngược lại
        return t->data;
    }
    else{
        return TimMax(t->pRight);
    }
}

// Xóa một node trong cây
void XoaNode(TREE &t, int data){
    if (t == NULL){
        return;
    }
    else{
        if (data < t->data){
            XoaNode(t->pLeft, data);
        }
        else if (data > t->data){
            XoaNode(t->pRight, data);
        }
        else{ // đã tìm ra node cần xóa
            //NODE *X = t;
            if(t->pLeft == NULL){ // Nếu node con bên trái NULL thì dùng node con bên phải thay thể vị trí node sẽ xóa
                t = t->pRight;
            }
            else if (t->pRight == NULL){ // Nếu node con bên trái NULL thì dùng node con bên trái thay thể vị trí node sẽ xóa
                t = t->pLeft;
            }
            else{

            }
        }
    }
}
// hàm nhập dữ liệu
void Menu(TREE &t){
    while (true)
    {
        system("cls");
        cout << "\n\n ============== MENU ==============";
        cout << "\n1. Nhap du lieu";
        cout << "\n2. Xuat du lieu";
        cout << "\n3. Dem so luong nguyen to";
        cout << "\n4. Tim kiem node trong cay";
        cout << "\n5. In node co 2 node con";
        cout << "\n6. Tim node lon nhat trong cay";
        cout << "\n7. Xoa 1 node bat ki trong cay";
        cout << "\n0. Thoat";
        cout << "\n\n ==================================";
        int luachon; 
        cout << "\nNhap lua chon: ";
        cin >> luachon;
        if (luachon > 7 || luachon < 0){
            cout << "\nLua chon khong hop le !";
            system ("pause");
        }
        else{
            if (luachon == 1){
                int x;
                cout << "\nNhap so nguyen x:";
                cin >> x;
                ThemNode(t, x);
            }
            else if (luachon == 2){
                cout << "\nDUYET CAY THEO NLR\n";
                DuyetNLR(t);

                system ("pause");
            }
            else if(luachon == 3){
                int dem = 0;
                cout << "So luong so nguyen to la: ";
                cout << DemSoLuongSoNguyenTo(t, dem);
                system ("pause");
            }
            else if(luachon == 4){
                cout << "Nhap gia tri can tim kiem: ";
                int x;
                cin >> x;
                cout << TimKiem(t, x);
                system ("pause");
            }
            else if(luachon == 5){
                cout << "Cac node co 2 node con la: ";
                InNode(t);
                system ("pause");
            }
            else if(luachon == 6){
                cout << "Node lon nhat trong cay la: ";
                cout << TimMax(t);
                system ("pause");
            }
            else if(luachon == 7){
                int data;
                cout << "Nhap node can xoa: ";
                cin >> data;
                XoaNode(t, data);
            }
            else{
                break;
            }
        }
    }
}
int main(){
    TREE t;
    KhoiTaoCay(t);
    Menu(t);
    system("pause");
    return 0;
}