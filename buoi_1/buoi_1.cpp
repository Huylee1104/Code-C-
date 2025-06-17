#include <bits/stdc++.h>

using namespace std;

// tìm số đảo của một số N (n>0) nhập từ bàn phím
int daoso(int x){
    int y;
    while(x > 0){
        y = y*10 +  x%10;// y lấy phần dư của x
        x /= 10; // làm mất số cuối của x
    }
    return y;
}

// Nhập dãy N số nguyên tìm min max, trung bình cộng 
void tim_min_max(int x, int a[]){
    int min = a[0];
    int max = a[0];
    float trungbinh = 0;
    for (int i = 0; i < x; i++){
        if (a[i] < min){
            min = a[i];
        }
        if (a[i] > max){
            max = a[i];
        }
        trungbinh += a[i];
        
    }
    trungbinh = trungbinh/x;
    cout << "Số nhỏ nhất là: " << min << "\n";
    cout << "Số lớn nhất là: " << max << "\n";
    cout << "Trung bình của mảng là: " << trungbinh;
}
// tìm dãy con tăng dài nhất từ mảng n phần tử: 
// 3 4 2 5 6 1 7
// 1 1 1 1 1 1 1
// 1 2
// 1 2 1
// 1 2 2 3
// 1 2 3 3 4
void daytang(int x, int a[]){
    int L[x];
    for (int i = 0; i < x; i++){
        L[i] = 1;
    }
    for (int i = 0; i < x; i++){
        for (int j = 0; j <= i; j++){
            if (a[i] > a[j] ){
                L[i] = max(L[i], L[j] + 1);
            }
        }
    }
    int max = 0;
    for (int i = 0; i < x; i++){
        if (L[i] > max){
            max = L[i];
        }
    }
    cout << max;
}

// nhập 1 mảng 2 chiều chỉ chứa 0 và 1, 
// tìm ra hình vuông/ hình chữ nhật lơn nhất chỉ toàn 1

int main(){
    int m;
    cout << "nhap so m : ";
    cin >> m;
    int  a[m];
    cout << "Nhap mang: ";
    for (int i = 0; i < m; i++){
            int y;
            cin >> y;
            a[i] = y;
    }
    daytang(m, a);
}