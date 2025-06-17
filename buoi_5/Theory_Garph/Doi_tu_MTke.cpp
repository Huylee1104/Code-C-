#include <bits/stdc++.h>

using namespace std;

// đổi từ ma trận kề sang danh sách canh
int a[1001][1001];
int n;
vector <pair<int, int>> edge;
vector <int> adj[1001];
void inp(){
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (a[i][j] == 1 && i > j){
                edge.push_back({i, j});
            }
        }
    }

    // in danh sach canh
    for (auto it : edge){
        cout << it.first << " " << it.second;
    }
}

// đổi từ ma trận kề sang danh sách kề
void inp2(){
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (a[i][j] == 1);
                adj[i].push_back(j);
        }
    }

    // in danh sach kề
    for(int i = 0; i < n; i++){
        cout << i << " : ";
        for (int x : adj[i]){
            cout << x << " ";
        }
        cout << endl;
    }
}
