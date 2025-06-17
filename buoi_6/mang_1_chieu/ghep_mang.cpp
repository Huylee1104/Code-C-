#include <iostream>

using namespace std;
// Ghép hai mảng đã sắp xếp thành một mảng giữ nguyên thứ tự
void Nhap_mang(int a[], int m){
    for (int i = 0; i < m; i++){
        int x; cin >> x;
        a[i] = x;
    }
}
// 3 5 7 11
// 2 3 3 12 15 20
// kĩ thuật 2 con trỏ: dùng 2 biến cho 2 mảng
// Chạy 2 biến, nếu phần tử mảng nào bé hơn thì in ra sau đó tăng biến tương ứng
// Sau khi chạy xong sẽ có 1 mảng hết trước, sau đó dùng vòng while kiểm tra phần tử 
// mảng nào lớn hơn biến tương ứng thì in ra tất cả phần tử còn lại
void Ghep_mang(int a[], int b[], int m, int n){
    int l1 = 0, l2 = 0;
    while(l1 < m && l2 < n){
        if (a[l1] < b[l2]){
            cout << a[l1] << " ";
            l1++;
        }
        else{
            cout << b[l2] << " ";
            l2++; 
        }
    }
    while (m > l1){
        cout << a[l1] << " ";
        l1++;
    }
    while(n > l2){
        cout << b[l2] << " ";
        l2++;
    }
}
int main(){
    int m,  n;
    cin >> m >> n;
    int a[m], b[n];
    Nhap_mang(a, m);
    Nhap_mang(b, n);
    Ghep_mang(a, b, m, n);
}