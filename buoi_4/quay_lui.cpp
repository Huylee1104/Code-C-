#include <bits/stdc++.h>
using namespace std;

// thuật toán quay lui
// sinh các oán vị của một tập gồm k bit. k = 3
// S = {000, 001, 010, 100, ... }
int n, a[100], k, used[100];

// hàm in kết quả
void kq(){
    for (int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

// hàm này theo nguyên lý LIFO
void banary(int i){ 
    for (int j = 0; j <=1; j++){
        a[i] = j; // nhận giá trị tại vị trí a[i] = j
        if (i == n){ // nếu số phần tử của i bằng số bit yêu cầu thì in ra
            kq();
        }
        else {
            banary(i + 1); // ngược lại gọi đệ quy hàm 
        }
    }
}

// tương tự hàm tạo bit nhị phân
// n: Số lượng phần tử của mảng, k : số lượng của 1 chỉnh vị
void chinh_vi(int i){
    // Với mỗi giá trị sau sẽ lơn hơn giá tri trước và giá trị tối đa của một mảng là n - k + i
    for (int j = a[i - 1] + 1; j <= n - k + i; j++){
        a[i] = j;
        if (i == k){
            kq();
        }
        else {
            chinh_vi(i + 1);
        }
    }
}

void hoan_vi(int i){
    for (int j = 1; j <= n; j++){
        if (used[j] == 0){ // biên used[j] lưu trạng thái đã được sử dụng hay chưa tại vị trí j
            a[i] = j;
            used[j] = 1; // nếu đã sử dụng thì chuyển sang 1
            if (i == n){
                kq();
            }
            else{
                hoan_vi(i + 1);
            }
            used[j] = 0; // sau khi sử dụng xong thì chuyển trạng thái tại j về 0
        }

    }
}

int main(){
    cout << "Nhap n: ";
    cin >> n;
    hoan_vi(1);
    return 0;
}