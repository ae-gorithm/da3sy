#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> w[n+1]; 
    bool visited[n+1] = {0, };
    int parent[n+1] = {0, };
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        w[a].push_back(b);
        w[b].push_back(a);
    }
    
    //bfs
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int num = q.front();
        q.pop();
        for (int j = 0; j < w[num].size(); j++) {
            if (visited[w[num][j]]) continue;
            visited[w[num][j]] = true;
            parent[w[num][j]] = num;
            q.push(w[num][j]);
        }
    }
    for (int i = 2; i < n+1; i++) cout << parent[i] << "\n";
}
