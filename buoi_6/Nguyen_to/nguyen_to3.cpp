#include <iostream>
#include <math.h>

using namespace std;

//Kiểm tra tính nguyên tố của số lớn (≤ 10^18) sử dụng Miller-Rabin
int nt(int n){
    if (n < 2) return 0;
    if (n == 2 || n == 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 4; i <= sqrt(n); i+=6){
        if (n % i == 0) return 0;
    }
    return 1;
}


//Tìm số nguyên tố thứ n trong dãy số nguyên tố 
int Tim(int n){
    int dem = 0; // lưu số thứ tự của số nguyên tố
    int count = 0; // chạy từ 0 đến khi dem == n
    while(dem != n){
        count++;
        if (nt(count)) dem++;
        
    }
    return count;
}

int main(){
    int a;
    cout << "Nhap vi tri so nguyen ro muon tim: ";
    cin >> a;
    cout << "So nguyen to o vi tri " << a << " la:";
    cout << Tim(a);
}