#include <bits/stdc++.h>

using namespace std;

int n, a[100], cot[100], d1[100], d2[100];
int x[100][100];
/* n: số dòng, cột của bàn cờ
a[]: lưu vị trí cột của quân hậu để in
cot[]: lưu trạng thái vị trí cột của quân hậu đang đứng
d1[]: lưu trạng thái vị trí đường chéo xuôi quân hậu đang đứng
d2[]: lưu trạng thái vị trí đường chéo ngược quân hậu đang đứng
1: chua có con hậu nào đứng trên đường đó
0: đã có 1 con hậu ở trên đường đó
*/
// yêu cầu: tìm các vị trí để mỗi quân hậu trên 1 hàng trên cờ vua không thể ăn nhau
// hàm in kết quả
void kq(){
    memset(x, 0, sizeof(x));
    for (int i = 1; i <= n; i++){
        x[i][a[i]] = 1; 
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << x[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void Queen(int i){
    for (int j = 1; j <=n; j++){
        if (cot[j] == 1 && d1[i - j + n] == 1 && d2[i + j -1] == 1){
            a[i] = j;
            cot[j] = d1[i - j + n] = d2[i + j -1] = 0;
            if (i == n){
                kq();
            }
            else{
                Queen(i + 1);
            }
            cot[j] = d1[i - j + n] = d2[i + j -1] = 1;
        }
    }
}

int main(){
    cout << "Nhap kich thuoc ban co: ";
    cin >> n;
    for (int i = 1; i <= 99; i++){
        cot[i] = d1[i] = d2[i] = 1;
    }
    Queen(1);
    return 0;
}