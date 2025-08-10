// 8/10 (일) 17:14 ~ 18:15 (약 1시간)
// 위상정렬 이름만 들어보고 알고리즘 몰라서 찾아봄
// 위상정렬 : 순서가 정해진 작업들의 전체 순서를 결정하는 알고리즘
// 전체 순서는 하나로 정해져있지 않고 진입 차수에 따라 여러 가지 정답이 나올 수도 있음
// O(V + E) : V-노드, E-간선

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> inDegree(n+1, 0); //진입 차수 : index로 들어오는 요소의 개수 / 0개이면 일반적으로 그게 시작인 겨
    vector<vector<int>> vec(n+1);
    for (int i = 0; i < m; i++) {
        int cnt;
        cin >> cnt;
        int arr[cnt];
        for (int j = 0; j < cnt; j++) {
            cin >> arr[j];
        }
        for (int j = 1; j < cnt; j++) {
            vec[arr[j-1]].push_back(arr[j]);
            inDegree[arr[j]]++;
        }
    }
    queue<int> q;
    vector<int> order;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) q.push(i);
    }
    for (int i = 0; i < n; i++) {
        if (q.empty()) { //q가 n개를 다 돌지 않았는데 비었다? -> 사이클이 생긴 거라 위상 정렬이 아님
            cout << 0 << "\n";
            return 0;
        }

        int curr = q.front(); q.pop();
        order.push_back(curr);
        for (int j = 0; j < vec[curr].size(); j++) {
            int next = vec[curr][j];
            inDegree[next]--;
            if (inDegree[next] == 0) q.push(next);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << order[i] << "\n";
    }
}
