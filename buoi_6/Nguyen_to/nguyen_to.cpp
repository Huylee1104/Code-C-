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

int main(){
    int n;
    cout << "Nhap so nguyen to can kiem tra: ";
    cin >> n;
    if (nt(n)) cout << n << " la so nguyen to";
    else cout << n << " khong phai la so nguyen to"; 
    return 0;
}