#include <bits/stdc++.h>
using namespace std;

int a[1001][1001];
int n, m;
vector <pair<int, int>> edge;
vector <int> adj[1001];

// đổi từ danh sách kề sang ma trận kề
int ipn(){
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        string s, num;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> num){
            a[i][stoi(num)] = 1;
        }
    }
    
    // in ma trận kề
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

// đổi từ danh sách kề sang danh sach canh
int inp2(){
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        string s, num;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> num){
            if (stoi(num) > i){
                edge.push_back({i, stoi(num)});
            }
        }
    }

    // in danh sach canh
    for (auto it : edge){
        cout << it.first << " " << it.second;
    }
}