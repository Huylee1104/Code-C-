#include <bits/stdc++.h>

using namespace std;

// Tìm k phần tử lớn nhất không sắp xếp
void Tim(int a[], int n, int k){
    int max = a[0];
    while (k > 0){
        int index;
        for (int i = 0; i < n ; i++){
            if (a[i] > max) {
                index = i;
                max = a[i];
            }
        }
        cout << max << " ";
        max = a[0];
        n = n - 1;
        for (int i = index; i < n; i++){
            a[i] = a[i + 1];
        }
        k--;
    }
}
int main(){
    int n, k;
    cin >> n;
    int a[n];
    cout << "Nhap mang: ";
    for (int i = 0; i < n ; i++){
        int x; cin >> x;
        a[i] = x;
    }
    cout << "Nhap so phan tu muon in: ";
    cin >> k;
    Tim(a, n, k);
    return 0;
}