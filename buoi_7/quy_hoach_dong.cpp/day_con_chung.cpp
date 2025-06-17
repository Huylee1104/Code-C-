#include <bits/stdc++.h>
using namespace std;

// Đề bài: Cho 2 xâu kí tự, tìm dãy con chung dài nhất (không cần liền kê)
// abdfge
// acde
// output : 3 (a d e)
int x[1001][1001]; // Lưu số phần tử con chung
int main(){
    string a, b;
    cin >> a >> b;
    int n1 = a.size();
    int n2 = b.size();
    a = '@' + a;
    b = '@' + b;
    memset(x, 0, sizeof(x));
    for(int i = 1; i <= n1; i++){
        for (int j = 1; j <= n2; j++){
            if (a[i] == b[j]){ // Nếu 2 kí tự giống nhau thì lấy độ dài xâu dài nhất trước đó cộng thêm 1
                x[i][j] = x[i - 1][j - 1] + 1;
            }
            else{
                x[i][j] = max(x[i][j - 1], x[i - 1][j]); // nếu 2 kí tự khác nhau sẽ lấy độ dài của giá trị xâu 2 bên trước đó
            }
        }
    }
    cout << endl << x[n1][n2];
}