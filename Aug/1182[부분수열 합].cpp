// 8/5 (화) 14:10 ~ 14:40 (30분)

#include<iostream>
using namespace std;

int n, s;
int num[21];
int cnt, sum;

void dfs(int x) { //백트래킹
    if (x == n) { //x는 n-1이면 하나 덜 돈 거임 n-1인덱스가 마지막이니까 그것까지 더해거나 빼고 확인해야 함
        if (sum == s) cnt++;
        return;
    }
    sum += num[x];
    dfs(x+1);
    sum -= num[x];
    dfs(x+1);
}

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> num[i];
    dfs(0);
    if (s == 0) cnt--; //공집합일 경우 합은 0이므로 한 개 빼줘야 함
    cout << cnt;
}
