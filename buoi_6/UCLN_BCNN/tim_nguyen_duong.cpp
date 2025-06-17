#include <iostream>

using namespace std;

// tìm số nguyên dương nhỏ nhất chia hết cho những số nguyên dương cho trước
// 3 6 5 => output: 30
int UCLN(int a, int b){

    if (b == 0){ //  chú ý đoạn này vì a % b nên a không thể = 0
        return a;
    }
    return UCLN(b, a % b); 
}

int BCNN(int a, int b){

    return abs(a * b) / UCLN(a, b);
}

int main(){
    int n;
    cin >> n;
    int a[n];
    int bc;
    for (int i = 0; i < n; i++){
        int x; cin >> x; 
        a[i] = x;
    }
    for (int i = 0; i < n; i++){
        if (i == 0){
            bc = BCNN(a[i], a[i + 1]);
        }
        else{
            bc = BCNN(bc, a[i]);
        }
    }
    cout << bc;
}