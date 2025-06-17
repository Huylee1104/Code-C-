#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;
//hàm đảo vị trí đầu thành cuối và cuối thành đầu
void reverse(int a[], int n){
    int l = 0, r = n -1;
    while(l < r){
        int tmp = a[l];
        a[l] = a[r];
        a[r] = tmp;
        l++; r--;
    }
}
// quy định là chuỗi a luôn lớn hơn b
/*
Cách làm: Không dùng trực tiếp là 1 số integer mà đưa vào xâu kí tự
Vì mảng là lưu từ đầu tới cuối, còn trừ thì từ cuối tới đầu
Nên khi tính t cần đảo ngược cả 2 mảng và sau khi tính xong thì đảo ngược kết quả
*/
void sub(char a[], char b[]){
    int n1 = strlen(a), n2 = strlen(b);
    int n = 0;
    int x[n1], y[n2], z[n1 + 1];
    for (int i = 0; i < n1; i++) x[i] = a[i] - '0';
    for (int i = 0; i < n2; i++) y[i] = b[i] - '0';
    reverse(x, n1);
    reverse(y, n2);
    for (int i = n2; i <= n1; i++){
        y[i] = 0;
    }
    int nho = 0;
    for (int i = 0; i < n; i++){
        int tmp = x[i] - (y[i] + nho);
        if (tmp < 0){
            z[n++] = 10 + tmp;
            nho = 1;
        }
        else{
            z[n++] = tmp;
            nho = 0;
        }
    }
    int ok = 0;
    for (int i = n -1; i >= 0; i++){
        if (ok == 0 && z[i] ){
            ok = 1;
        }
        if (ok) cout << z[i];
    }
    if (ok = 0) cout << 0;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        char c[1001], d[1001];
        cin >> c >> d;
        if (strlen(c) > strlen(d) || (strlen(c) == strlen(d) && strcmp(c, d)>0)){
            sub(c, d);
        }
        else{
            cout <<"-";
            sub(d, c);
        }
        cout << "endl";
    }
    return 0;
}