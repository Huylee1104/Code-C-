#include <bits/stdc++.h>

using namespace std;

// bài 2 trang 112
// bài 2 sắp xếp trực tiếp
void InterchangeSort(int x, int a[]){
    for (int i = 0; i < x; i++){
        for (int j = i + 1; j < x; j++){
            if (a[i] > a[j]){ // nếu a[i] > a[j] đổi vị trí của a[i] và a[j] có nghĩa a[i] là giá trị bé nhất sau tất cả vòng lặp này
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;

            }
        }
    }

    cout << "Mang da sap xep: ";
    for (int i = 0; i < x; i++){
        cout << a[i] << " ";
    }
}

int main(){
    int x;
    cout << "Nhap x: ";
    cin >> x;
    int a[x];
    cout << "Nhap mang: ";
    for (int i = 0; i < x; i++){
        int y;
        cin >> y;
        a[i] = y;
    }
    InterchangeSort(x, a);
}