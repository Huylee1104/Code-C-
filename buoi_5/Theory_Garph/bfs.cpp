#include <bits/stdc++.h>

using namespace std;
// Thuật toán tìm kiếm theo chiều rộng BFS
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

void bfs(int u){
    queue <int> q; // khởi tạo một query
    q.push(u); // đưa phần tử u vào query
    visited[u] = true; // đánh dấu trạng thái tại u đã được duyệt
    while(!q.empty()){
        int v = q.front(); //  Lấy đỉnh đầu của hàng đợi
        q.pop(); // xóa đỉnh đầu của hàng đợi
        cout << v << " "; // in vị trí v ra màn hình
        for (int x : adj[v]){ // duyệt các phần tử gần đỉnh x
            if (visited[x] = false){ // nếu vị trí x chưa được duyệt qua
                q.push(x); // đưa x vào query
                visited[x] = true; // đánh dấu đã duyệt qua.
            }
        }
    }
}

int main(){
    cin >> n >> m;
    inp();
    bfs(1);
    return 0;
}
