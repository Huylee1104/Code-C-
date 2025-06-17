#include <bits/stdc++.h>

using namespace std;

// Đề: Kiểm tra có tập con có tổng bằng S hay không, các số chỉ sử dụng một lần
// Input: S = 10: 4 2 5 3 1 => output: có
/*
ý tưởng: Vì các số chỉ được dùng 1 lần. Cần duyệt các số trong mảng trước và duyện từ 10 trờ về a[i]
Dùng 1 mảng khác để lưu trạng thái. Nếu có thể sử dụng các số trong mảng để tạo thành tổng thì thay đổi trạng thái.
Công thức truy hồi: if (a[j - a[i]]) a[j] = true
*/
void TongS(int n, int a[], int S){
    bool dp[S + 1];
    for (int i =0 ; i <= S; i++) dp[i] = false;
    dp[0] = true; // Nếu tạo ra tổng là 0 thì không cần làm gì
    for (int i = 0; i < n; i++){
        for (int j = S; j >= a[i]; j--){
            if (dp[j - a[i]]) dp[j] = true;
        }
    }
    if (dp[S] == true) cout << 1;
    else cout << 0;
}

int main(){
    int n, S;
    cin >> n >> S;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    TongS(n, a, S);
    return 0;
}