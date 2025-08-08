//레벨은 낮은데... 문제 원리 파악이 어려웠음...
// 8/8(금) 14:07 ~ 14:40
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i<=n; i++) {
        if (30%(i+1) == 0) cout << i <<"\n";
    }
}
