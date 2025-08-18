// 8/18 (월) 17:41 ~ 18:42
// bfs 응용... 좌표로 가면 너무 어렵다... 하
// 나중에 꼭 또 다시 풀기

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    int lab[n][m];
    vector<pair<int, int>> viruses;
    vector<pair<int, int>> zeros;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> lab[i][j];
            if (lab[i][j] == 0) zeros.push_back({i, j});
            if (lab[i][j] == 2) viruses.push_back({i, j});
        }
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int max = 0;

    for (int a = 0; a < zeros.size(); a++) {
        for (int b = a+1; b < zeros.size(); b++) {
            for (int c = b+1; c < zeros.size(); c++) {
                pair<int, int> wall1 = zeros[a];
                pair<int, int> wall2 = zeros[b];
                pair<int, int> wall3 = zeros[c];

                vector<vector<bool>> visited(n, vector<bool> (m, 0));
                queue<pair<int, int>> q;
                int expanded = 0;
                for (auto v : viruses) q.push(v);

                while (!q.empty()) {
                    pair<int, int> curr = q.front(); q.pop();
                    for (int i = 0; i < 4; i++) {
                        int nextX = curr.first + dx[i];
                        int nextY = curr.second + dy[i];

                        if (nextX >= n || nextX < 0 || nextY < 0 || nextY >= m) continue;
                        if (lab[nextX][nextY] != 0) continue;
                        if ((nextX == wall1.first && nextY == wall1.second)|| (nextX == wall2.first && nextY == wall2.second) || (nextX == wall3.first && nextY == wall3.second)) continue;
                        if (visited[nextX][nextY]) continue;

                        visited[nextX][nextY] = true;
                        expanded++;
                        q.push({nextX, nextY});
                    }
                }

                int normal = zeros.size() - 3 - expanded;
                if (max < normal) max = normal;
            }
        }
    }
    cout << max;
}
