// 8/25 (월) 14:54 ~ 16:04 (1시간 10분)

#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> belt(2*n, 0);
    vector<bool> robot(n, false);
    for (int i = 0; i < n*2; i++) cin >> belt[i];

    int step = 0;
    while (1) {
        step++;

        //1번
        int last = belt[2*n - 1];
        for (int i = 2*n-1; i > 0; i--) belt[i] = belt[i-1];
        belt[0] = last;
        for (int i = n-1; i > 0; i--) robot[i] = robot[i-1];
        robot[n-1] = false;
        robot[0] = false;

        //2번
        for (int i = n-1; i > 0; i--) {
            if (!robot[i] && robot[i-1] && belt[i] > 0) {
                robot[i] = robot[i-1];
                robot[i-1] = false;
                belt[i]--;
            }
        }
        robot[n-1] = false;

        //3번
        if (belt[0] > 0 && !robot[0]) {
            robot[0] = true;
            belt[0]--;
        }

        //4번
        int cnt = 0;
        for (int i = 0; i < 2*n; i++) {
            if (belt[i] == 0) cnt++;
        }
        if (cnt >= k) break;
    }
    cout << step;
}
