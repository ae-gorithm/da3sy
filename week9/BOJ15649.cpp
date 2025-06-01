#include<iostream>
#include<vector>
using namespace std;

int n, m;
bool visited[10];
vector<int> v(10);

void dfs(int x) {
    if (x > m) {
        for (int i = 1; i <= m; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        v[x] = i;
        dfs(x+1);
        visited[i] = false;
    }
    
}

int main() {
    cin >> n >> m;
    dfs(1);
}
