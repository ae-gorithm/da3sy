#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int power[n], joy[n];

    int init = 100;
    //세준이 처음 체력 : 100
    int dp[init] = {0};

    for (int i = 0; i < n; i++) {
        cin >> power[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> joy[i];
    }
    for (int i = 0; i < n; i++) {
        for (int p = init-1; p >= power[i]; p--) {
            dp[p] = dp[p] > (dp[p-power[i]] + joy[i]) ? dp[p] : dp[p-power[i]] + joy[i];
        }
    }
    int max = 0;
    for (int i = 1; i < 100; i++) {
        max = max > dp[i] ? max : dp[i];
    }
    cout << max;
}

//TC1
//i = 0
//dp[99] ~ dp[1] = 20, dp[0] = 0
//dp[99] ~ dp[22] = 20 + 30 = 50, dp[21] = 30, dp[20] ~ dp[1] = 20, dp[0] = 0
//dp[99] ~ dp[79] = 20 + 25 = 45?, dp[78] ~ dp[22] = 50, dp[21] = 30, dp[20] ~ dp[1] = 20, dp[0] = 0
//dp[20] + 25 or dp[99] = 45 or 50 -> 50
//1, 21, 79 -> 21 + 79 = 100, 최대 99까지만 가능

//82%에서 틀림 - 1~99만 봐야 함 마지막 for문
