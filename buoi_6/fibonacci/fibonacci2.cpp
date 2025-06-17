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

//Tìm số Fibonacci nhỏ nhất lớn hơn N
int Tim(int n){
    int count = 1;
    while(fibonacci(count) <= n){
        count++;
    }
    return fibonacci(count);
}
int main(){
    int n; 
    cout << "Nhap so can kiem tra: ";
    cin >> n;
    cout << Tim(n);
    return 0;
}