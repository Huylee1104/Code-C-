#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i< n; i++ ) cin >> a[i];
    // Xay dung mang hieu
    long long D[n + 5];
    for (int i = 0; i< n; i++){
        if (i == 0) D[i] = a[i];
        else {
            D[i] = a[i] - a[i - 1];
        }
    }
    cout << "Nhap test case: ";
    int q; cin >> q;
    while(q--){
        int l, r, k;
        D[l] += k;
        D[r + 1] -= k;
    }
    long long sum = 0;
    for (int i = 0; i < n; i++){
        sum += D[i]; // Chỗ này chọn phương pháp là in ra luôn chứ không lưu giá trị vào mạng
        // giá trị sau sẽ bằng tổng giá trị trước đó cộng cho giá trị hiện tại
        cout << sum << " ";
    }
    return 0;
}