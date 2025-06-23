#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int day[n];
    int pay[n];
    int dp[n];
    int max = 0;
    for (int i = 0; i < n; i++) {
        cin >> day[i] >> pay[i];
        dp[i] = pay[i];
        for (int j = 0; j < i; j++) { //오늘 자 이익 기준으로 전 것들 비교해서 더해야 함
            if (j + day[j] <= i) {
                if (dp[j] + pay[i] > dp[i]) {
                    dp[i] = dp[j] + pay[i];
                }
            }
        }
        if (dp[i] > max && i + day[i] < n+1 ) max = dp[i]; //마지막 날 고려 (예시 기준)
    }
    cout << max;
}
