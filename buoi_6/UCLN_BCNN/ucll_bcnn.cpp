#include <iostream>
#include <cstdlib> // để dùng abs()

using namespace std;

int UCLN(int a, int b){

    if (b == 0){ //  chú ý đoạn này vì a % b nên a không thể = 0
        return a;
    }
    else {
        return UCLN(b, a % b); 
    }
}

int BCNN(int a, int b){

    return abs(a * b) / UCLN(a, b);
}

int main(){
    int a, b;
    cout << "Nhap lan luot a va b: ";
    cin >> a >> b;
    cout << "UCLN: " << UCLN(a, b) << endl;
    cout << "BCNN: " << BCNN(a, b);
    return 0;
}
