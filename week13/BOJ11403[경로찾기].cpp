#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            if (a == 1) {
                vec[i].push_back(j);
            }
        }
    }

    vector<vector<int>> ans(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        queue<int> q;
        q.push(i);
        while(!q.empty()) {
            int num = q.front();
            q.pop();
            for (int next : vec[num]) {
                if (ans[i][next] == 1) continue;
                ans[i][next] = 1;
                q.push(next);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}
