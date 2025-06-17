#include <iostream>
#include <math.h>

using namespace std;
int a[1005];

// 1 1 2 3 5 8 13 21 34
int fibonacci(int n){
    a[1] = a[2] = 1;
    for (int i = 3; i <= n; i++){
        a[i] = a[i - 1] + a[i - 2];
    }
    return a[n];
}
//Tính tổng F(1) + F(2) + ... + F(n) mod p
int Tinh(int n, int p){
    int sum = 0;
    int tinh;
    for (int i = 1; i <= n; i++){
        sum +=fibonacci(i);
    }
    tinh = sum % p;
    return tinh;
}
int main(){
    int n, p;
    cout << "Nhap lan luot n va p: ";
    cin >> n >> p;
    cout << Tinh(n, p);
    return 0;
}