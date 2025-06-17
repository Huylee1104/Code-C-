#include <bits/stdc++.h>

using namespace std;
int n, m, s, t;// n là đỉnh, m là cạnh, s là đỉnh đầu, t là đỉnh cần đến

vector <int> adj[1001]; // một mảng các vector lưu danh sach kề tại 1 đỉnh
bool visited[1001]; // mảng này dùng để đánh dấu trạng thái đã duyệt hay chưa
int parent[1001]; // kiểm tra cha (đỉnh trước đó) của 1 đỉnh

// đổi danh sach canh sang danh sach ke
void inp(){
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
// thuật toán tìm đường theo chiều sâu DFS
void dfs(int u){
    visited[u] = true;
    for (int x : adj[u]){
        if (visited[x] == false){
            parent[x] = u;// Lưu giá trị đỉnh trước đó của x
            dfs(x);
        }
    }
}

void Path(int s, int t){
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    dfs(s);
    if (!visited[t]){
        cout << "Khong tim duoc duong!";
    }
    else{
        vector<int> path; // mảng dùng để truy vết ngược lại từ t về s
        while(t != s){
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        for (int x : path) cout << x << " ";
    }
}
int main(){
    cin >> n >> m;
    inp();
    cout << "Nhap dinh bat dau va dinh ket thuc: ";
    cin >> s >> t;
    Path(s, t);
}