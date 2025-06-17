#include <bits/stdc++.h>

using namespace std;
// Thuật toán tìm kiếm theo chiều sâu DFS
//  Chuyển từ danh sách cạnh sang danh sách kề
int n, m;// n là đỉnh, m là cạnh

vector <int> adj[1001]; // một mảng các vector lưu danh sach kề tại 1 đỉnh
bool visited[1001]; // mảng này dùng để đánh dấu trạng thái đã duyệt hay chưa

void inp(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){ 
        int x, y; cin >> x >> y;
        adj[x].push_back(y); // mảng vô hướng
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited)); // khởi tạo tất cả phần tử trong mảng visited = false
}

void dfs(int u){
    cout << u; // in ra đỉnh u
    visited[u] = true; // đánh dấu đỉnh u đã được duyệt
    for(int x : adj[u]){ // duyệt các phần tử gần đỉnh u
        if (visited[x] == false) dfs(x); // Nếu phần tử x chưa được duyệt gọi đệ quy với x
    } 
}

int main(){
    cin >> n >> m;
    inp();
    dfs(1);
}