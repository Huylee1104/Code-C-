#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
int a[1001][1001];
int d[1001][1001];

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};// lưu chỉ số của hàng i khi di chuyển theo cạnh chung
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};// lưu chỉ số của cột j khi di chuyển theo canh chung

// Đề bài : Mã ở vị trí bất kì hãy đếm số bước nó có thể đi trong 1 bàn cơ n cột
// Đánh dấu tất cả các 0 mã chưa đi qua là 0 và ô đi qua sẽ là 1
void inp(){
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            a[i][j] = 0;
            d[i][j] = 0;
        }
    }
}

void bfs(int i, int j){
    queue <pair<int, int>> q;
    q.push({i, j});
    a[i][j] = 1;
    d[i][j] = 1; ++cnt;
    while(!q.empty()){
        pair <int, int> v = q.front();
        q.pop();
        for (int k = 0; k < 8; k++){
            int i1 = v.first + dx[k];
            int j1 = v.second + dy[k];
            if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < n && a[i1][j1] == 0){
                d[i1][j1] = ++cnt;
                q.push({i1, j1});
                a[i1][j1] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    inp();
    bfs(0, 0);
}