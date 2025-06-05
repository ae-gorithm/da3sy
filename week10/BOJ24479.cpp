#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[100001];
bool visited[100001];
vector<int> v[100001];
int cnt = 1;

void dfs(int x) {
    visited[x] = true;
    arr[x] = cnt;
    cnt++;
    for (int i = 0; i < v[x].size(); i++) {
        if (!visited[v[x][i]])
            dfs(v[x][i]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m,r;
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 0; i < n+1; i++) {
        sort(v[i].begin(), v[i].end());
    }
    dfs(r);
    for (int i = 1; i < n+1; i++) {
        cout << arr[i] << "\n";
    }
}
