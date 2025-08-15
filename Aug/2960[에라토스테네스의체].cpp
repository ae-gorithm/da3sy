// 8/15 (금) 22:05 ~ 22:17
// 1차 : 89% 틀렸습니다.
// 2차 : 맞음 - 가장 바깥 for문 범위 이슈
// 에라토스테네스 코드 안 보고 푼 거 첨임 우하하

#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<bool> isPrime(n+1, false);
    int cnt = 0;
    for (int i = 2; i < n+1; i++) {
        if (isPrime[i]) continue;
        for (int j = i; j < n+1; j += i) {
            if (isPrime[j]) continue;
            isPrime[j] = true;
            cnt++;
            if (cnt == k) {
                cout << j;
                return 0;
            }
        }
    }
}
