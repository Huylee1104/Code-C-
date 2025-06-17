#include <bits/stdc++.h>
using namespace std;

int m, n;
char a[1001][1001];

int dx[4] = {-1, 0, 0, 1};// lưu chỉ số của hàng i khi di chuyển theo cạnh chung
int dy[4] = {0, -1, 1, 0};// lưu chỉ số của cột j khi di chuyển theo canh chung

// Đề bai nếu là # có cạnh cùng nhau thì tính là 1 thành phần liên thông
void inp(int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
}
// * # # * *
// # * * # #
// * * # # *
// # # * * *
void bfs(int i, int j){
    queue <pair<int, int>> q; // Một hàng đợi với kiểu dữ liệu pair
    q.push({i, j}); // Đưa chỉ số đầu tiên vào hàng đợi
    a[i][j] = '*'; // đánh dấu chỗ đó đã được duyệt qua
    while(!q.empty()){
        pair <int, int> v = q.front(); // lưu cặp chỉ số đầu tiên cho v
        q.pop(); // xóa cặp chỉ số đó khỏi hàng đợi
        for (int k = 0; k < 4; k++){
            int i1 = v.first + dx[k]; // i1 là chỉ số mới của dòng bằng chỉ số của dòng trước đó + thêm/ bớt đơn vị
            int j1 = v.second + dy[k];// j1 là chỉ số mới của cột bằng chỉ số của cột trước đó + thêm/ bớt đơn vị
            if (i1 >= 0 && i1 < m && j1 >= 0 && j1 < n && a[i1][j1] == '#'){
                q.push({i1, j1}); // Đưa cặp chỉ số thỏa điều kiện vào hàng đợi
                a[i1][j1] = '*'; // đánh dấu cặp chỉ số đó đã được duyệt qua
            }
        }
    }
}

// Đếm số thành phần liên thông
/*
Ý tưởng: Duyệt từ đầu mảng 2 chiều tới cuối mảng 2 chiều đếm xem có bao nhiêu kí tự thảo điều kiện
Vì khi gọi hàm bfs thì sẽ đánh dấu các phần tử liên thông nên các phần từ kề nhau chỉ thỏa điều kiện 1 lần
*/
int Dem(int m, int n){
    int cnt = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (a[i][j] == '#'){ 
                cnt++;
                bfs(i, j);
            }
        }
    }
    return cnt;
}

int main(){
    cin >> m >> n;
    inp(m, n);
    cout << Dem(m, n);
    return 0;
}