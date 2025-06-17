#include <bits/stdc++.h>
using namespace std;

// Đề: Cho 1 mảng n phần tử và tổng S. Nếu tổng các phần tử bất kì trong n bằng S 
// thì in ra 1 không bằng in ra 0 (1 số sử dụng được 1 lần)
// {2, 3, 5, 6} S = 12 => output: 0

int main(){
    int n, S;
    cin >> n >> S;
    int a[n], dp[S + 1]; // mảng dp lưu trạng thái của 1 số từ 1 đến S
    for (int i = 0; i< n; i++) cin >> a[i];
    memset(dp, 0 , sizeof(dp));
    dp[0] = 1;
    for (int i = 0 ; i < n; i++){
        for (int j = S; j >= a[i]; j--){
            if (dp[j - a[i]]){
                dp[j] = 1;
            }
        }
    }
    for (int i = 0; i <= S; i++){
        cout << dp[i] << " ";
    }
}