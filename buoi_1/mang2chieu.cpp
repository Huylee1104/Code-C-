#include <bits/stdc++.h>

using namespace std;

int main(){
    int m, n;
    cout << "nhap so m, n: ";
    cin >> m >> n;
    int  a[m][n];
    cout << "Nhap mang: ";
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            int y; cin >> y;
            a[i][j] = y;
        }
    }
    cout << "Mang da nhap: " << endl;
    for (int i =0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << a[j][i] << " ";
        }
        cout << "\n";
    }
}