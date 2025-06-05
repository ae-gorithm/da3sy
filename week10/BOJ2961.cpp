#include<iostream>
using namespace std;

int n;
int s[10], b[10];
int mini = -1;
bool visited[10];
long long sm = 1;
long long bs = 0;

void dfs(int x, long long sm, long long bs, int cnt) {
    if (x == n){
        if (cnt > 0) {
            int gap = abs(sm - bs);
            if (gap < mini || mini == -1) mini = gap;
        }
        return;
    }
    dfs(x+1, sm * s[x], bs + b[x], cnt + 1);
    dfs(x+1, sm, bs, cnt);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> b[i];
    }
    dfs(0, 1, 0, 0);
    cout << mini;
}
