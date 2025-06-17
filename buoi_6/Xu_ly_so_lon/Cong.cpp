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
Vì mảng là lưu từ đầu tới cuối, còn cộng thì từ cuối tới đầu
Nên khi tính t cần đảo ngược cả 2 mảng và sau khi tính xong thì đảo ngược kết quả
*/
void add(char a[], char b[]){
    int n1 = strlen(a), n2 = strlen(b);
    int n = 0; // BIến n dùng để chạy khi lưu kết quả
    int x[n1], y[n1], z[n1 + 1];
    // Chuyển dữ liệu từ kí tự sang mảng số để tính
    for (int i = 0; i < n1; i++) x[i] = a[i] - '0';
    for (int i = 0; i < n2; i++) y[i] = b[i] - '0';
    // Đảo ngược 2 mảng
    reverse(x, n1); 
    reverse(y, n2);
    // Để dễ tính toán thì các phần tử trống ở mảng y sẽ chuyển thành 0
    for (int i = n2; i <= n1; i++){
        y[i] = 0;
    }
    int nho = 0; // Lưu khi tổng phép tính này lơn hơn 10 thì phép tính sau sẽ nhớ 1
    for (int i = 0; i < n1; i++){
        int tmp = x[i] + y[i] + nho;
        z[n++] = tmp % 10;
        nho = tmp / 10;
    }
    if (nho) z[n++] = nho; //  Nếu sau khi tính xong mà nho khác 0 thì vị trí tiếp theo của mảng z là 1
    // In đảo ngược kết quả tính được sẽ thành kết quả của bài
    for (int i = n -1; i >= 0; i++) {
        cout << z[i];
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        char c[1001], d[1001];
        cin >> c >> d;
        if (strlen(c) > strlen(d)) add(c, d);
        else add(d, c);
        cout << "endl";
    }
    return 0;
}