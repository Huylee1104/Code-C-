#include <bits/stdc++.h>
using namespace std;

// Đề: Cho dãy số tìm số lượng phần tử tăng dài nhất trong mảng (Không cần liên tiếp)
// 2 5 1 3 7 9 => output: 4
int main(){
    int n;
    cin >>n;
    int a[n], dp[n]; // mảng dp dùng để lưu giá trị dài nhất của dãy con
    for (int i = 0; i < n; i++){
        cin >> a[i];
        dp[i] = 1;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            if (a[i] > a[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int max = 0;
    for (int i = 0; i < n; i++){
        if (dp[i] > max) max = dp[i];
    }

    cout << max;
}