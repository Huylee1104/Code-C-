#include <bits/stdc++.h>

using namespace std;
int n, S; // n là đồng xu, S là tổng cần tính
int dp[100001];
const int MOD = 1e9 + 7;
// Đề: Từ tập các đồng xu đếm số cách tạo thành tổng S (Các đồng xu được sử dụng nhiều lần)
// 1 2 3 4 5 6 7 8 9
// {2, 3, 5}
int main(){
    cin >> n >> S;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < S; i++) dp[i] = 0;
    dp[0] = 1;
    for (int i = 1; i <= S; i++){
        for (int c = 0; c < n; c++){
            if (i >= c){
                dp[i] = (dp[i] + dp[i - a[c]]) % MOD;
            }
        }
    }
    cout << dp[S];
    return 0;
}

