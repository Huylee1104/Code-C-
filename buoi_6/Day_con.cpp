#include <iostream>

using namespace std;

// Dãy con có tổng lớn nhất: 2 -5 8 2 -4 6 9 -5 => output: 21
int main(){
    int n;
    cin >> n;
    int a[n];
    int sum1 = 0, sum2 = -9999;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        a[i] = x;
    }
    for (int i = 0; i < n; i++){
        sum1 += a[i];
        sum2 = max (sum2, sum1);
        if (sum1 < 0){
            sum1 = 0;
        }
    }
    cout << sum2;
    return 0;
}