#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

/*
Cách làm bài toán xử lý số lớn:
B1: Không tính ở dạng số nguyên mà phải tính ở dạng xâu
B2: Chuyển từ xâu sang mảng số nguyên
B3: Đổi vị trí đầu cuối của mảng 
B4: Tính toán và đảo ngược kết quả
*/
// hàm đảo
void Dao(int a[], int n){
    int l = 0; int r = n - 1;
    while(l < r){
        int tmp = a[l];
        a[l] = a[r];
        a[r] = tmp;
        l++; r--;
    }
}
//  2 2 6 4 = > 4 6 2 2
//  4 7 1   = > 1 7 4
void multi(char a[], char b[]){
    int x1 = strlen(a);
    int x2 = strlen(b);
    int x[x1], y[x2], z[x1+x2 + 1] = {0};
    for (int i = 0; i < x1; i++) x[i] = a[i] - '0';
    for (int i = 0; i < x2; i++) y[i] = b[i] - '0';
    Dao(x, x1);
    Dao(y, x2);
    int nho = 0;
    int i, j;
    for (i = 0; i < x2; i++){ //  mảng b
        for (j = 0; j < x1; j++){ // mang a
            z[i + j] += y[i] * x[j];
            nho = z[i + j] / 10;
            if (z[i + j] >= 10){
                z[i + j + 1] += nho;
                z[i + j] %= 10;
            }
        }
    }
    int dem = x1 + x2 + 1;
    while (dem > 1 && z[dem - 1] == 0) dem--;
    for (int i = dem - 1; i >= 0; i--){
        cout << z[i];
    }

}
int main(){
    char c[1001], d[1001];
        cin >> c >> d;
        multi(c, d);
        cout << "\n";
    return 0;
} 