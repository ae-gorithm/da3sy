// 8/22 (금) 14:36 ~ 15:11(35분)
// 우선 dfs거나 union-find가 가장 먼저 생각났음
// 근데 union-find는 완전 부모 하나라 생각해 보니 그냥 dfs인 것 같은데
// 최소한의 강의실 = 그리디?
// dfs로 푸는 게 아닌 것 같다는 생각이 다시 듦

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> time;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        time.push_back({a, b});
    }
    sort(time.begin(), time.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        if (!pq.empty() && pq.top() <= time[i].first) pq.pop();
        pq.push({time[i].second});
    }
    cout << pq.size();
}
