#include<iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    int cnt = 1;
    while (x > 1) {
        if (x % 2 == 1) cnt++;
        x /= 2;
    }
    cout << cnt << "\n";
}
