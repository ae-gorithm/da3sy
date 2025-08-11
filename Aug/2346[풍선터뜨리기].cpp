// 8/11 (월) 11:33 ~ 12:26
// 1차 : 8% 틀림 - 2차 정답
// 배열로 하려 하다니... 멍청한 생각...

#include<iostream>
#include<deque>
using namespace std;

int main() {
    int n;
    cin >> n;
    deque<pair<int, int>> dq;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        dq.push_back({i+1, a});
    }
    while (!dq.empty()) {
        int num = dq.front().first;
        int move = dq.front().second;
        cout << num << " ";
        dq.pop_front();
        bool isPos = move > 0 ? true : false;
        while (1) {
            if (move == 1 || move == 0) break;
            if (isPos) {
                auto [a, b] = dq.front();
                dq.push_back({a,b});
                dq.pop_front();
                move--;
            } else {
                auto [a, b] = dq.back();
                dq.push_front({a,b});
                dq.pop_back();
                move++;
            }
        }
    }
}
