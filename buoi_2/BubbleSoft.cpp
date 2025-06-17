#include <bits/stdc++.h>

using namespace std;

// làm bài 3 4 5 slice 57

// bài 3 sắp xếp nổi bọt tăng dần
void BubbleSoft(int x, int a[]){
    int count = 0;
    int dem = 0;
    for (int i = 0; i < x; i++){
        for (int j = x -1; j > i; j--){
            dem++; // đếm số lần thực hiện vòng lăp
            if (a[j] < a[j - 1]){ // Neu vi tri a[j] < a[j - 1] thi doi cho
                int tmp = a[j];
                a[j] = a[j - 1];
                a[j -1] = tmp;
                count++; // đếm số lần hoán đổi
            }
        }
    }
    cout << "Mang da sap xep: ";
    for (int i = 0; i < x; i++){
        cout << a[i] << " ";
    }
    cout << "\nSo lan da hoan doi: " << count << "\n";
    cout << "So lan vao vong lap: " << dem << "\n";
}

// bài 5 sắp xếp nổi bọt cai tien tăng dần
void BubbleSoft2(int x, int a[]){
    int swapped = 1, i = 0;
    int dem = 0;
    while (swapped){
        swapped = 0;// set swapped = 0, vong lap se dung neu ko doi cho o buoc nuoc
        for (int j = x -1; j > i; j--){
            dem++;
            if (a[j] < a[j - 1]){// Neu vi tri a[j] < a[j - 1] thi doi cho
                int tmp = a[j];
                a[j] = a[j - 1];
                a[j -1] = tmp;
                swapped = 1;
            }
        }
        i++;
    }
    cout << "Mang da sap xep: ";
    for (int i = 0; i < x; i++){
        cout << a[i] << " ";
    }
    cout << "\nSo lan vao vong lap: " << dem << "\n";
}

// bài 4 sắp xếp nổi bọt cai tien giảm dần
void BubbleSoft3(int x, int a[]){
    int swapped = 1, i = 0;
    while (swapped){
        swapped = 0;// set swapped = 0, vong lap se dung neu ko doi cho o buoc nuoc
        for (int j = x -1; j > i; j--){
            if (a[j] > a[j - 1]){// Neu vi tri a[j] < a[j - 1] thi doi cho
                int tmp = a[j];
                a[j] = a[j - 1];
                a[j -1] = tmp;
                swapped = 1;
            }
        }
        i++;
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
    BubbleSoft(x, a);
    BubbleSoft2(x, a);

}