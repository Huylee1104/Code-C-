#include <iostream>

using namespace std;

//Tìm dãy con liên tiếp có tổng lớn nhất (Kadane's algorithm)
// -4 6 2 -5 4 2 9 => output: 18
// cộng tổng dãy có tổng > 0, nếu  < 0, cho đếm phần tử kế tiếp

int Kadane(int a[], int n){
    int sum1 = 0; // lưu tổng tạm thời
    int sum2 = -9999; // lưu tổng lớn nhất
    for (int i = 0; i < n; i++){
        sum1 += a[i];
        sum2 = max(sum1, sum2);
        if (sum1 < 0) sum1 = 0;
    }
    return sum2;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    cout << "Nhap mang: ";
    for (int i = 0; i < n ; i++){
        int x; cin >> x;
        a[i] = x;
    }
    cout << Kadane(a, n);
    return 0;
}