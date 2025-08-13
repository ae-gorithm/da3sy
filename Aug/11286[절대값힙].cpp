// 8/13 (수) 13:31 ~ 13:41 (10분) 
// 실1
// 에전에는 힙을 두 개 생성했었는데 하나만 해서 코드 가독성도 향상하는 방향으로 감 우하하 성장했군

#include<iostream>
#include<queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num == 0) {
            if (pq.empty()) {
                cout << 0 <<"\n";
            }
            else {
                cout << pq.top().second <<"\n";
                pq.pop();
            }
            continue;
        }
        pq.push({abs(num), num});
    }
}
