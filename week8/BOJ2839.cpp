#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt5 = n/5;
    int cnt3 = (n%5)/3;
    while (cnt5*5 + cnt3*3 != n && cnt5 >= 0) {
        int rem = n - cnt5*5;
        cnt3 = rem/3;
        if (rem % 3 != 0) {
            cnt5--;
        }
    }
    if (cnt5 == -1) cout << cnt5;
    else cout << cnt5+cnt3;
}
