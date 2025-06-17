#include <iostream>
#include <math.h>

using namespace std;

//Tìm nghiệm nguyên của phương trình ax² + bx + c = 0
// delta = b*b - 4 ac
// x1 = (-b + sqrt(delta))/2*a*b
// x2 = (-b - sqrt(delta))/2*a*b
void Timnghiem(int a, int b, int c){
    if (c == 0 && a != 0 && b != 0 ){
        cout << 0 << " " << -b/a;
    }
    else if (a == 0){
        cout << -c/b;
    }
    else{
        float delta = b*b - 4*a*c;
        float x1, x2;
        if (delta < 0) cout << "Phuong trinh vo nghiem";
        else if (delta == 0){
            x1 = x2 = -b/2*a;
        }
        else{
            x1 = (-b + sqrt(delta))/2*a*b;
            x2 = (-b - sqrt(delta))/2*a*b;
        }
        
        if (x1 == (int)x1) cout << x1 << " ";
        if (x2 == (int)x2) cout << x2;
    }
}
int main(){
    //ax² + bx + c = 0
    int a, b, c;
    cout << "Nhap lan luot a, b, c: ";
    cin >> a >> b >> c;
    Timnghiem(a, b, c);
    return 0;
}