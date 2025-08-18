// 8/18 (월) 16:31 ~ 17:37

// 1차 : 50% 틀렸습니다.
// dfs 아니고 생각해 보니 bfs로 풀어야 함
// 2차 : 3% 틀림..?
// 3차 : 42% 틀림
// while문 추가했다고 이게 되네..;; 당연함 해당 타이밍에 들어간 큐에 있는 값들에 대해 전부 depth를 계산 해 줘야함...;;
// 그래도 혼자 dfs, bfs 이제 어느 정도 응용 되는 듯...?

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> vec(n+1);
    vector<int> bacon(n+1, 0);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    for (int i = 1; i < n+1; i++) {
        vector<bool> visited(n+1, false);
        queue<int> q;
        q.push(i);
        int depth = 0;
        visited[i] = true;
        while (!q.empty()) {
            int qs = q.size();
            depth++;
            while(qs--) {
                int curr = q.front(); q.pop();
                for (int i = 0; i < vec[curr].size(); i++) {
                    if (visited[vec[curr][i]]) continue;
                    visited[vec[curr][i]] = true;
                    q.push(vec[curr][i]);
                    bacon[vec[curr][i]] += depth;
                }
            }
        }
    }

    int minBacon = bacon[1];
    int index = 1;
    for (int i = 1; i < n+1; i++) {
        if (minBacon > bacon[i]) {
            minBacon = bacon[i];
            index = i;
        }
    }
    cout << index;
}
