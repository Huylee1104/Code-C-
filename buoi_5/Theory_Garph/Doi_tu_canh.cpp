#include <bits/stdc++.h>

using namespace std;
int n, m;
int a[1001][1001];
vector <int> adj[1001];
// danh sách cạnh sang ma trận kề
void inp(){ 
    for (int i = 0; i < m; i++){ 
        int x, y; cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }

    // in ra ma trận kề
    for (int i = 0; i < n ; i++){
        for (int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

// danh sách cạnh sang danh sách kề
void inp2(){
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // in ra danh sach ke
    for (int i = 0; i < n; i++){
        cout << i << " : ";
        for (int x : adj[i]){
            cout << x << " ";
        }
        cout << endl;
    }
}