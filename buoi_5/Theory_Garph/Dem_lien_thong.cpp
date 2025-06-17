#include <bits/stdc++.h>

using namespace std;
int n, m;// n là đỉnh, m là cạnh

vector <int> adj[1001]; // một mảng các vector lưu danh sach kề tại 1 đỉnh
bool visited[1001]; // mảng này dùng để đánh dấu trạng thái đã duyệt hay chưa

void inp(){
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}
void dfs(int u){
    visited[u] = true;
    for (int x : adj[u]){
        if (visited[x] == false){
            dfs(x);
        }
    }
}

void Dem(){
    int ans = 0; // Đếm số lượng thành phần liên thông
    for (int i = 0; i < n; i++){
        if(visited[i] == false){ // Lúc nào cũng có 1 thành phần liên thông
            ans++;
            dfs(i); // Duyệt tất cả các phần tử liên thông với i
            // Vì duyệt liên thông của i là đánh dấu tất cả thành phần liên thông với i
            // Nếu có phần tử i nào đó được 1 lần nữa có nghĩa là nó không liên thông với i trước đó
        }
    }
}

int main(){
    cin >> n >> m;
    inp();
    Dem();
}