//dfs로도 풀 수 있을 것 같다!
//한 번 풀고 바로 푸니까 조금 그새 손에 익는 느낌
//bfs에서 큐에 넣는 거 잊지 말기!

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vec(n+1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    
    int cnt = 0;
    bool visited[n+1] = {0, };
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        queue<int> q;
        q.push(i);
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            if (visited[curr]) continue;
            visited[curr] = true;
            for (int i = 0; i < vec[curr].size(); i++) {
                q.push(vec[curr][i]);
            }
        }
        cnt++;
    }
    
    cout << cnt;
}
