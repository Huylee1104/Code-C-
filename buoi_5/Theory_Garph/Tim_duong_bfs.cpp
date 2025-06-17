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

// Tim đường theo chiều rộng
void bfs(int u){
    queue <int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for (int x : adj[v]){
            if (visited[x] == false){
                q.push(x);
                visited[x] = true;
                parent[x] = v;
            }
        }
    }
}

void Path(int s, int t){
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    bfs(s);
    if (!visited[t]){
        cout << "Khong tim thay duong !";
    }
    else{
        vector <int> path;
        while (t!=s){
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