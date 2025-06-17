#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

//Tìm số hạng thứ n của cấp số cộng/nhân khi biết các hạng khác
// công thức CSC: uₙ = u₁ + (n − 1)·d
// Biết 2 số hạng khác =>  Cần tìm U1 và d
//u₃ = u₁ + 2d = 7
//u₆ = u₁ + 5d = 16
// Cách làm lưu số đã biết vào 1 pair (chỉ sổ, giá trị) : (3, 7)
int CSC(pair<int, int> so1, pair<int, int> so2, int n){
    int d = (so2.second - so1.second)/(so2.first - so1.first);
    int u1 = so1.second - (so1.first - 1)*d;
    int un = u1 + (n - 1)*d;
    return un;
}

// công thức CSN: vₙ = v₁ · q⁽ⁿ⁻¹⁾
// biết 2 số hạng khác => tìm v1 và q
//v₂ = v₁ · q = 6
//v₅ = v₁ · q⁴ = 162
int CSN(pair<int, int> so1, pair<int, int> so2, int n){
    int q = pow( (so2.second/ so1.second), 1 / (so2.first - so1.first));
    int v1 = so1.second/ (pow(q, so1.first -1));
    int vn = v1 * pow(q, n -1);
    return vn;
}

int main(){
    pair <int, int> so1;
    pair <int, int> so2;
    cout << "Nhap chi so va gia tri so thu 1:";
    cin >> so1.first >> so1.second;
    cout << "Nhap chi so va gia tri so thu 2: ";
    cin >> so2.first >> so2.second;
    cout << "Nhap so can tinh: ";
    int n; cin >> n;
    cout << "Cap so cong cua 2 so tren la: ";
    cout << CSC(so1, so2, n);
    cout << "\nCap so nhan cua 2 so tren la: ";
    cout << CSN(so1, so2, n);
    return 0;
}