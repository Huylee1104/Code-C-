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
// Kiểm tra một số có thuộc dãy Fibonacci không
bool Tim(int x){
    int count = 1;
    if (x == 1) return true;
    while (count <= x){
        if (fibonacci(count + 1) == x){
            return true;
            break;
        }
        count++;
    }
    return false;
}
int main(){
    int n;
    cout << "Nhap so can kiem tra: ";
    cin >> n;
    if (Tim(n) == true) cout << "La so fibonacci";
    else cout << "Khong phai la so fibonacci";
    return 0;
}