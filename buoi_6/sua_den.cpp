#include <iostream>

using namespace std;

// bài toàn sửa đèn dùng cửa sổ trượt
/*
Nhập vào 3 số: N K B
N: Tổng số đèn
K: Số đèn liên tiếp cần sáng
B: Số đèn hỏng
*/
int main(){
    int n, k, b;
    cout << "Nhap tong so den va so den sang lien tiep: ";
    cin >> n >> k;
    cout << "\nNhap so luong den hong: ";
    cin >> b;
    int a[1001] = {0};
    for (int i = 1; i <= b; i++){
        cout << "Vi tri den hong: ";
        int x; cin >> x;
        a[x] = 1;  // Vị trí đèn hỏng
    }
    int den = 0; // Lưu số đèn hỏng trong khu vực
    for (int i = 1; i <= k; i++){
        if (a[i] == 1){
            den++; // Nếu đèn hỏng thì cộng thêm 1
        }
    }
    int cnt = den; // Số đèn trong một khu vực hỏng it nhất
    for (int i = k + 1; i <= n; i++){
        if (a[i - k] == 1) den--; // Nếu vị trí đầu tiên là đèn hỏng thì số đèn hỏng trong khu vực tiếp theo trừ 1 đèn
        if (a[i] == 1) den++; //  Nếu vị trí vừa mới thêm vào là đèn hỏng thì số đèn hỏng trong khu vực tiếp theo cộng 1 đèn
        cnt = min(cnt, den); // So sánh tổng đèn hỏng cửa vị trí mới và vị trí trước đó
    }
    cout << "So den can sua la: " << cnt;
    return 0;
}