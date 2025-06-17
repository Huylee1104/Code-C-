#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;
// Tính giai thừa của số lớn
/*
ý tưởng: dùng xâu để tính
đầu vào là chuỗi string -> chuyển từng kí tự thành số để tính, sau khi tính xong -> chuyển số về lại kí tự
*/

string giai_thua(string n, int x){
    int tich = 0, nho = 0; // Biến tich để luu tich của số cần nhân, nho lưu phần nhớ nến tích > 10
    string ketqua = "", tam = ""; // ketqua lưu kết quả tạm thời, biến tam lưu nếu nho sau cùng khác 0
    for (long long i = n.size() - 1; i >= 0; i--){
        tich = (n[i] - 48) * x + nho; // n[i] là kí tự - 48 thành số để nhân với x
        nho = tich/10;
        ketqua = (char)(tich % 10 + 48) + ketqua; // chuyển số nhận được từ tích thành kí tự + biến ketqua.
    }
    if (nho > 0){
        tam = to_string(nho); // hàm to_string() chuyển số thành chuỗi
    }
    return tam + ketqua;
}
int main(){
    int n; // số cần tính
    cin >> n;
    string gt = "1"; // chuỗi ban đầu có chuỗi là "1"
    for (int i = 1; i <= n; i++){ // Đếm từ 1-> n <=> 1.2.3.4...n
        gt = giai_thua(gt, i);
    }
    cout << gt;
    return 0;
}