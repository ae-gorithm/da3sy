#include<iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int num[n];
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += num[j];
            if (sum == m) cnt++;
        }
    }
    cout << cnt;
}
//3중 for 문 했다가 시간 초과 나서 2중 for문으로 줄임 -> 성공~
