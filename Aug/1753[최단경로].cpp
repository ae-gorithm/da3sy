//8/8 (금) 12:57 ~ 13:57
// 유니온 파인드로 pair 할당해서 할 수 있을 줄 알았는데 못하는 거였음...
// 다익스트라는 단어만 알지 개념 자체는 거의 몰라서 그냥 인터넷 찾아보기 시작 (13:17)
// 큰 틀에서 bfs 같음

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int INF = 1e9;
int v, e, start;
vector<pair<int,int>> graph[20001];
vector<int> weight(20001, INF); //start에서 index로 가는 가중치

void dijkstra(int s) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,s});
    while(!pq.empty()) {
        pair<int,int> tmp = pq.top(); pq.pop();
        for (auto [index, w] : graph[tmp.second]) {
            if (weight[index] > w + tmp.first) {
                weight[index] = w + tmp.first;
                pq.push({weight[index], index});
            }
        }
    }
}

int main() {
    cin >> v>> e;
    cin >> start;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    weight[start] = 0;
    dijkstra(start);
    for (int i = 1; i <= v; i++) {
        if (weight[i] == INF) cout << "INF\n";
        else cout << weight[i] <<"\n";
    }
}
