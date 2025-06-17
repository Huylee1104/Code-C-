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


//Tìm cặp số nguyên tố sinh đôi (p, p+2) trong khoảng cho trước
void Tim(int a, int b){
    for (int i = a; i <= b; i++){
        if (nt(i) && nt(i + 2)) {
            cout << "("<< i << ", " << i + 2 << ")" << endl;
        }
    }
}
int main(){
    int a, b;
    cout << "Nhap khoang cach can tim: ";
    cin >> a >> b;
    Tim(a, b);
    return 0;
}