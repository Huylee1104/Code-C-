#include <bits/stdc++.h>
using namespace std;

// Đề bài: Cho 1 xâu kí tự, Tìm số lượng kí tự đối xứng dài nhất
// abbcaacd
// output : 4 (caac)
int x[1001][1001];
int k;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    s = '@' + s;
    memset(x, 0, sizeof(x));
    int ans = 1; // ít nhất là đối xứng bằng 1
    for (int i = 1; i <= n; i++){
        x[i][i] = 1;
    }
    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= n - i + 1; j++){
            k = j + i - 1;
            if (i == 2){
                if (s[j] == s[k]) x[j][k] = 1;               
            }
            else{
                if ((s[j] == s[k] && x[i + 1][j - 1] == 1)) x[j][k] = 1;
            }
            if (x[j][k]) ans = max(ans, i); // Nếu khoảng cách là i và có kí tự thứ j giống kí tự thứ k thì 
                                            //nghĩa là đối xứng dài nhất hiện tại cách nhau là i
        }
    }
}