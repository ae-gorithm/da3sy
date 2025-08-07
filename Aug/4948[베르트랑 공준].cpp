// 8/7 (목) 11:37 ~ 11:55 (18분)

#include<iostream>
#include<vector>
using namespace std;

int MAX = 123456 * 2;
vector<bool> isPrime(MAX + 1, true);

void calPrime() {
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i*i <= MAX; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    calPrime();
    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;
        int cnt = 0;
        for (int i = n+1; i <= 2*n; i++) {
            if (isPrime[i]) cnt++;
        }
        cout << cnt <<"\n";
    }
}

// 1차 : 생각해 보니 2중 for문이기 때문에 10% 시간 초과
// 에라토스테네스의 체인가 그거 어떻게 구현하는지 기억이 안 남...
// 에라토스테네스의 체로 isPrime 배열에 선 할당 후 for문 없이 배열에서 isPrime을 찾는 방식으로 변경해야 함 -> 외우자!!!!

//2년 전에 메모리랑 시간 복잡도 엄청 크게 나왔었는데 확 줄어든 거 보고 너무 신기함.. 우하하
