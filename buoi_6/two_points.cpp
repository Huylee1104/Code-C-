#include <iostream>

using namespace std;

// Nhập mảng
void NhapMang(int n, int a[]){
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
}
// gộp 2 mảng có thứ tự tăng dần thành 1 mảng
void Tron(int a[], int b[], int n, int m){
    int i = 0, j = 0;
    while(i < n && j < m){
        if (a[i] < b[j]){
            cout << a[i] << " ";
            i++;
        }
        else{
            cout << b[j] << " ";
            j++;
        }
    }
    while (i < n){
        cout << a[i] << " ";
        i++;
    }
    while (j < m){
        cout << b[j] << " ";
        j++;
    }
}

int main(){
    cout << "Nhap lan luot so luong phan tu cua 2 mang: ";
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    cout << "Nhap mang dau tien: ";
    NhapMang(n, a);
    cout << "Nhap mang tiep theo: ";
    NhapMang(m, b);
    cout << "Day sau khi tron: ";
    Tron(a, b, n, m);
}