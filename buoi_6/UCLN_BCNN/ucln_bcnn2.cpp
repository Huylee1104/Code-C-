#include <iostream>

using namespace std;

int UCLN(int a, int b){

    if (b == 0){ //  chú ý đoạn này vì a % b nên a không thể = 0
        return a;
    }
    return UCLN(b, a % b); 
}

int BCNN(int a, int b){

    return abs(a * b) / UCLN(a, b);
}

// Đếm số cặp (a,b) với a,b ≤ N thỏa mãn ƯCLN(a,b) = d và BCNN(a,b) = m
// Nhược điểm cách này độ phức tạp lớn không tối ưu
int Dem(int n, int d, int m){
    int dem = 0;
    for (int i = 1; i <= n; i++){
        for (int j = n; j >= i; j--){
            if (UCLN(i, j) == d && BCNN(i, j) == m) {
                dem+=2;
                cout << i << " " << j << "\n";
                cout << j << " " << i << "\n";
            }
        }
    }
    return dem;
}

int main(){
    int n, d, m;
    cout << "Nhap so n can gioi han: ";
    cin >> n;
    cout << "Nhap so d va m can kiem tra: ";
    cin >> d >> m;
    cout << Dem(n, d, m);
    return 0;
}