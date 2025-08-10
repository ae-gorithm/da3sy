// 8/10 (일) 18:30 ~ 18:38
// 뭐지 규칙 찾다보니 너무 쉽게 나옴 우하하

#include<iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (n % 2 == 0 || m % 2 == 0) {
        cout << "A";
    } else cout << "B";
}
