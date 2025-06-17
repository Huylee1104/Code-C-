#include <iostream>
#include <math.h>

using namespace std;
//Tính tổng các số trong khoảng [a,b] chia hết cho k

int Tong(int a, int b, int k){
    int sum = 0;
    for (int i = a; i <= b; i++){
        if (i % k == 0) sum += i;
    }
    return sum;
}
int main(){
    int a, b, k;
    cout << "Nhap khoang: ";
    cin >> a >> b;
    cout << "Nhap so can chia: ";
    cin >> k;
    cout << Tong(a, b, k);
}