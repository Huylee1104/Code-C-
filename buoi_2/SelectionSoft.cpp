#include <bits/stdc++.h>
#include <utility>

using namespace std;

// bài 2 3 trang 74

// bài 2 sap xep chon
void SelectionSoft(int x, int a[]){
    int count = 0;
    for (int i = 0; i < x; i++){
        int min = a[i];
        for (int j = i + 1; j < x; j++ ){
            if (a[j] < min){ // 3 < 100
                int tmp = a[j]; // tmp = 3
                a[j] = min; // a[j] = 100
                min = tmp; // min = 3
                count++;
            }
        }
        a[i] = min; // gán giá trị bé nhất cho a[i]
    }
    cout << "Mang da sap xep: ";
    for (int i = 0; i < x; i++){
        cout << a[i] << " ";
    }
    cout << "\nSo lan da hoan doi: " << count;
}

// bài 3 một mảng gồm các cặp số nguyên (x, y), sắp xếp mảng theo thứ tự:
// Ưu tiên tăng dần theo x, nếu x bằng nhau thì giảm dần theo y

// nhập 1 mảng với tại mỗi vị trí sẽ gồm 2 giá trị => dùng pair để lưu
void SelectionSoft2(int x){
    pair <int, int> a[x]; // cấu trúc pair < datatype 1, datatype 2> name_pair;
    for (int i = 0; i < x; i++){
        int y; cin >> y;
        int z; cin >> z;
        a[i] = make_pair(y, z); // hàm make pair dùng để tạo giá trị vào pair
    }

    for (int i = 0; i < x; i++){        
            int min = a[i].first, min2 = a[i].second;
            for (int k = i + 1; k < x; k++ ){
                if (a[k].first < min){ 
                    int tmp = a[k].first; 
                    a[k].first = min; 
                    min = tmp; 

                    int tmp2 = a[k].second;
                    a[k].second = min2;
                    min2 = tmp2;
                }
            }
            a[i].first = min; 
            a[i].second = min2;
    }

    for (int i = 0; i < x; i++){
        if (a[i].first == a[i + 1].first || a[i].first == a[i - 1].first){
            int max = a[i].first, max2 = a[i].second;
            for (int k = i + 1; k < x; k++ ){
                if (a[k].second > max){ 
                    int tmp = a[k].first; 
                    a[k].first = max; 
                    max = tmp; 

                    int tmp2 = a[k].second;
                    a[k].second = max2;
                    max2 = tmp2;
                }
            }
            a[i].first = max; 
            a[i].second = max2;
        }
    }

    cout << "Mang da sap xep: ";
    for (int i = 0; i < x; i++){
        cout << a[i].first << " " << a[i].second << "\n";
    }
}

int main(){
    int x;
    cout << "Nhap x: ";
    cin >> x;
    // int a[x];
    // cout << "Nhap mang: ";
    // for (int i = 0; i < x; i++){
    //     int y;
    //     cin >> y;
    //     a[i] = y;
    // }
    // SelectionSoft(x, a);
    SelectionSoft2(x);
}