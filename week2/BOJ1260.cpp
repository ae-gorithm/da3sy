//이전에 풀어본 문제였다.
//bfs, dfs 간만에 하니까 다 까먹어서... 계속 자주 풀고 외워야 할 듯하다...

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

bool visited[1001];
vector<vector<int>> vec(1001);

void dfs(int v) {
    if (visited[v]) return;
    
    visited[v] = true;
    cout << v << " ";
    
    for (int i = 0; i < vec[v].size(); i++) {
        dfs(vec[v][i]);
    }
}

void bfs(int v) {
    queue<int> q;
    q.push(v);
    
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        if (visited[curr]) continue;
        
        cout << curr << " ";
        visited[curr] = true;
        for (int i = 0; i < vec[curr].size(); i++) {
            q.push(vec[curr][i]);
        }
    }
}


int main() {
    int n, m, v;
    cin >> n >> m >> v;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) {
        sort(vec[i].begin(), vec[i].end());
    }
    
    dfs(v);
    cout << "\n";
    for (int i = 0; i < n+1; i++) visited[i] = false;
    bfs(v);
}
