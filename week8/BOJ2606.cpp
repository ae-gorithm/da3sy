#include<iostream>
#include<vector>
using namespace std;

bool visited[101];
int cnt = 0;
vector<int> vec[101];

void dfs(int x) {
    if (visited[x]) return;
    cnt++;
    visited[x] = true;
    for (int i = 0; i < vec[x].size(); i++) {
        dfs(vec[x][i]);
    }
}

int main() {
    int com;
    cin >> com;
    int line;
    cin >> line;
    for (int i = 0; i < line; i++) {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    dfs(1);
    cout << cnt-1;
}
