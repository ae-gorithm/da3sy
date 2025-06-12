//예제도 안 풀림;;

#include<iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int N = 2*n;
    int a[N];
    bool robot[N] = {0, };
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int step = 0;
    while(1) {
    for (int i = 0; i < N; i++) {
        if (i-1 < 0) { // 1단계
            a[i] = a[i + N - 1];
            robot[i] = robot[i + N -1];
        } else {
            a[i] = a[(i-1) % N];
            robot[i] = robot[(i-1)% N];
        }
        if (i == n-1 && robot[n-1]) robot[n-1] = false; //1단계
        
        if (i+1 < n && !robot[i+1] && a[i+1] > 0) { //2단계
            if (i-1 < N) {
                robot[i+1] = robot[i];
            } else {
                robot[i] = robot[(i-1) % N];
            }
            a[i]--;
            if (i == n-1 && robot[n-1]) robot[n-1] = false;
        }
        
        //3단계
        if (a[0] != 0) {
            robot[0] = true;
            a[0]--;
        }
        step++;
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (a[j] == 0) cnt++;
            if (cnt >= k) {
                cout << step;
                return 0;
            }
        }
    }
    }
}
