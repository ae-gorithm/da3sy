// 8/22 (금) 13:49 ~ 14:30 (40분)
// 1차 : 16% 틀림

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int board[n][n];
        pair<int, int> curr, goal;
        cin >> curr.first >> curr.second;
        cin >> goal.first >> goal.second;

        int cnt = 0;
        if (curr == goal) {
            cout << cnt << "\n";
            continue; //break;라 해서 틀렸었음 2차 성공
        }

        int dx[8] = {-2,-2, 2, 2, -1, -1, 1, 1};
        int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push(curr);
        vis[curr.first][curr.second] = true;
        
        while (!q.empty()) {
            bool flag = false;
            int size = q.size();
            cnt++;

            for (int j = 0; j < size; j++) {
                auto [x, y] = q.front(); q.pop();
                for (int i = 0; i < 8; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if (vis[nx][ny]) continue;
                    vis[nx][ny] = true;
                    if (nx == goal.first && ny == goal.second) {
                        flag = true;
                        break;
                    }
                    q.push({nx, ny});
                }
                if (flag) break;
            }
            if (flag) break;
        }
        cout << cnt <<"\n";
    }
}
