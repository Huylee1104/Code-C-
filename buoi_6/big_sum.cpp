#include <iostream>

using namespace std;

// Cho 1 mảng tìm tổng lớn hơn số K với số phần tử liên tiếp bé nhất
// ví dụ: 2 6 4 3 6 8 9. K = 3 => output: 3 (6 + 8 + 9 > 20)
int main(){
    int n, k;
    cout << "Nhap lan luot so phan tu va so K can kiem tra: ";
    cin >> n >> k;
    int a[n];
    cout << "Nhap mang: ";
    for (int i = 0; i< n; i++){
        int x; cin >> x;
        a[i] = x;
    }
    int r, l = 0, sum, cnt = 9999;
    for (int r = 0; r < n; r++){
        sum +=a[r]; // Nếu sum < k tiếp tục cộng vào sum a[r]
        while(sum >= k){
            cnt = min(cnt, r -l +1); // Khi sum > k thì cập nhật chỉ số min của số phần tử liên tiếp có tổng lơn hơn k
            sum -= a[l]; // Trừ giá trị phần tử đầu tiên khỏi sum để kiểm tra biến 
                        //sum có còn lớn hơn k hay không để cập nhật cnt min
            l++; // Tăng chỉ số của l
        }
    }
    cout << cnt;
    return 0;
}