#include <bits/stdc++.h>
using namespace std;

int w[1001];// lưu khối lượng
int v[1001];// lưu giá trị
int a[1001][1001]; // lưu giá trị tối đa của túi của vật thứ i và khi khối lượng túi là j
int n, S; // n là số lượng vật, S là khối lượng túi có thể mang
// Đề bài: Một cái túi có thể mang vô số vật miễn khối lượng vật 
// bằng hoặc bé hơn khối lượng cái túi có thể mang, đếm giá trị tối đa túi có thẻ mang
int main(){
    cin >> n >> S;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) cin >> v[i];
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= S; j++){
            a[i][j] = a[i - 1][j]; // Nếu vật thứ i - 1 là tối đa của cái túi thì giá trị ít nhất của i là i - 1
            if (j >= w[i]){
                a[i][j] = max(a[i - 1][j], a[i - 1][j - w[i]] + v[i]);
                // giá trị lớn nhất của túi trước đó và giá trị của túi tại thời điểm khi trừ đi 
                // khối lượng vật sẽ bỏ vào cộng giá trị của vật khi thêm vào
            }
        }
    }
    //cout << a[n][S];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= S; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}