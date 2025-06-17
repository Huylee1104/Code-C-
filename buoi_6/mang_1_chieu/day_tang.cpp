#include <iostream>

using namespace std;
//Tìm dãy con tăng dài nhất (không cần liên tiếp)
// 2 5 3 6 4 9 => output: 4 (2 5 6 9)
// ý tưởng: dùng 1 mảng l[n] gán cho tất cả phần tử ban đầu là 1 (vì nếu ko tăng thì dãy tăng dài nhất là 1)
// Duyệt từ j -> i, i sẽ cố định - > dựa từng chỉ số của j trước đó để tìm chỉ số i lớn nhất
/*
          2 5 3 6 4 9
for i = 0 1 1 1 1 1 1
for i = 1 1 2 1 1 1 1
for i = 2 1 2 2 1 1 1
for i = 3 1 2 2 3 1 1
for i = 4 1 2 2 3 3 1
for i = 5 1 2 2 3 3 4
*/
int day_tang(int a[], int n){
    int l[n];
    for (int i = 0; i < n; i++){
        l[i] = 1; // Gán tất cả các phần tử bằng 1 vào mảng l[n]
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j ++){
            if (a[i] > a[j]){
                l[i] = max(l[i], l[j] + 1); 
                /*Tại vị trí i sẽ tìm chỉ số của i lớn nhất từ các phần tử trước đó*/
            }
            
        }
    }
    int max  = 0;
    for (int i = 0; i < n; i++){
        if (l[i] > max) max = l[i];
    }
    return max;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        a[i] = x;
    }
    cout << day_tang(a, n);
    return 0;
}