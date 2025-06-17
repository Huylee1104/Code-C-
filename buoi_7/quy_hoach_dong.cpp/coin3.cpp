#include <bits/stdc++.h>

using namespace std;
int n, S; // n là đồng xu, S là tổng cần tính
int dp[100001];
const int MOD = 1e9 + 7;
// Đề: Từ tập các đồng xu đếm số cách tạo thành tổng S (Mỗi cách tính 1 lần, không tính cách đảo vị trí)
// 1 2 3 4 5 6 7 8 9
// {2, 3, 5}
int main(){
    cin >> n >> S;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < S; i++) dp[i] = 0;
    dp[0] = 1;
    for (int i = 0; i < n; i++){
        for (int c = 1; c <= S; c++){
            if (c >= i){
                dp[c] = dp[c] + dp[c - a[i]];
            }
        }
    }
    for (int i = 1; i <= S; i++){
        cout << dp[i] << " ";
    }
    return 0;
}

