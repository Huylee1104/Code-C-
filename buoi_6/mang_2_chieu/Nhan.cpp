#include <iostream>

using namespace std;

const int MAX = 100;
void Nhap(int a[][MAX], int x, int y){
    for(int i  = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            int k; cin >> k;
            a[i][j] = k;
        }
    }
}
void Xuat(int a[][MAX], int x, int y){
    for(int i  = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
// Nhân 2 ma trận thì số dòng của ma trận này phải bằng số cột của ma trận kia: 2 x 3 và 3 x 2 -> 2 x 2
// 1 2 3  4 5     
// 4 5 6  6 7 => 
//        8 9
void Nhan(int a[][MAX], int b[][MAX], int x, int y, int z){
    int c[MAX][MAX];
    for (int i = 0; i < x; i++){
        for (int j = 0; j < z; j++){
            for (int k = 0; k < y; k ++){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    Xuat(c, x, z);
}


int main(){
    int x, y, z; 
    // x: số dòng ma trận 1
    // y: số cột ma trận 1 và số dòng ma trận 2
    // z: số cột ma trận 2
    cout << "Nhap so dong va cot cua ma tra 1: ";
    cin >> x >> y;
    cout << "Nhap so cot cua ma tra 2: ";
    cin >> z;
    int a[MAX][MAX];
    int b[MAX][MAX];
    Nhap(a, x, y);
    Nhap(b, y, z);
    Nhan(a, b, x, y, z);
}