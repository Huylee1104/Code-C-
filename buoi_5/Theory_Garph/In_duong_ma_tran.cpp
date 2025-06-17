#include <bits/stdc++.h>
using namespace std;

int m, n;
int s1, s2; //lưu chỉ số của điểm bắt đầu
int e1, e2; // Lưu chỉ số của vị trí kết thúc
char a[1001][1001];
int d[1001][1001]; // Lưu số bước đi
int dx[4] = {-1, 0, 0, 1};// lưu chỉ số của hàng i khi di chuyển theo cạnh chung
int dy[4] = {0, -1, 1, 0};// lưu chỉ số của cột j khi di chuyển theo canh chung

// Đề bài : In đường ngắn nhất giữa 2 điểm nếu có
// * # # * *
// A * # # #
// * * * * *
// # * * B *
// * là đường đi
void inp(int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
            if (a[i][j] == 'A'){
                s1 = i;
                s2 = j;
            }
            else if (a[i][j] == 'B'){
                e1 = i; e2 = j;
            }
        }
    }
}

void bfs(int s1, int s2){
    queue <pair<int, int>> q;
    q.push({s1, s2});
    a[s1][s2] = '#';
    d[s1][s2] = 0;
    while (!q.empty()){
        pair <int, int> v = q.front();
        q.pop();
        for (int k = 0; k < 4; k++){
            int i1 = v.first + dx[k];
            int j1 = v.second + dy[k];
            if (i1 >= 0 && i1 < m && j1 >= 0 && j1 < n && a[i1][j1] != '#'){
                d[i1][j1] = d[v.first][v.second] + 1;
                if (a[i1][j1] == 'B') return;
                q.push({i1, j1});
                a[i1][j1] = '#';
            }
        }
    }
}

int main(){
    cin >> m >> n;
    inp(m, n);
    bfs(s1, s2);
    if (!d[e1][e2]) cout << "Khong co duong";
    else cout << d[e1][e2];
}