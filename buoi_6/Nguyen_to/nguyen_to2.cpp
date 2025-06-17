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


//Đếm số nguyên tố trong khoảng [a,b] sử dụng sàng Eratosthenes
int Eratosthenes(int a, int b){
    int x[b+1];
    int dem = 0;
    for (int i = 0; i <= b; i++){
        x[i] = 1; // Đánh dấu tất cả các phần tử đều là 1
    }
    x[0] = x[1] = 0; // 2 phần tử này không phải là số nguyên tố nên gán thành 0
    for (int i = 2; i <= sqrt(b); i++){
        for (int j = i*i; j <= b; j += i){ 
            x[j] = 0; // Với mỗi số j xuất hiện thì không phải là số nguyên tố (do nó là tổng từ 1 số nào đó)
            // ví dụ i = 2 => j: 4 6 8 10 
        }
    }
    for (int i = a; i <= b; i++){
        if (x[i] == 1) dem++;
    }
    return dem;
}
int main(){
    int a, b;
    cout << "Nhap lan luot a va b: ";
    cin >> a >> b;
    cout << "So luong so nguyen to trong khoang tren: ";
    cout << Eratosthenes(a, b);
    return 0;
}