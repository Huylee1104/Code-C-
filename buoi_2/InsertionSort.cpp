#include <bits/stdc++.h>

using namespace std;
// bài 2 3 trang 91
// bài 2 sắp xếp chèn
// 8 5 
void InsertionSort(int x, int a[]){
    int pos, k; // pos lưu vị trí cần xét, k lưu giá trị sẽ xét
    for (int i = 1; i < x; i++){
        k = a[i]; // xét giá trị tại a[i]
        pos = i - 1; // vị trí cần thay thế nếu có
        while (pos >= 0 && a[pos] > k){ // dùng khi nào pos < 0 hoặc k > giá trị tại pos
            a[pos + 1] = a[pos]; // Nếu k < giá trị tại pos thì dịch chuyển giá trị tại pos sanh pos + 1
            pos--; // giảm pos 1 đơn vị
        }
        a[pos + 1] = k; 
        // Nếu không thực hiện vòng while thì vị trí như cũ, nếu thực hiện vòng while thì sẽ thay đổi
        // vì lúc này vị trí pos bị lùi hơn 1 đơn vị do vòng lặp while và đồng thời 
        // giá trị tại pos + 1 lúc sau không thay đổi nên sẽ gán giá trị của k ban đầu vào vị trí này
    }
    cout << "Mang da sap xep: ";
    for (int i = 0; i < x; i++){
        cout << a[i] << " ";
    }
}

int main(){
    int x;
    cout << "Nhap x: ";
    cin >> x;
    int a[x];
    cout << "Nhap mang: ";
    for (int i = 0; i < x; i++){
        int y;
        cin >> y;
        a[i] = y;
    }
    InsertionSort(x, a);
}