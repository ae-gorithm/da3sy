//8/5(화) 13:23 ~ 13:45 (22분)

#include<iostream>
#include<algorithm> //find 함수 쓰려면 algorithm 라이브러리 필요, 안 그러면 컴파일 에러 주의
#include<deque>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    deque<int> dq;
    for (int i = 1; i <=n; i++) dq.push_back(i);
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        auto it = find(dq.begin(), dq.end(), num);
        if (it - dq.begin() <= dq.size()/2) {
            while(dq.front() != num) {
                int tmp = dq.front();
                dq.pop_front();
                dq.push_back(tmp);
                cnt++;
            }
        } else {
            while(dq.front() != num) {
                int tmp = dq.back();
                dq.pop_back();
                dq.push_front(tmp);
                cnt++;
            }
        }
        dq.pop_front(); //얘가 루프 이후에 수행돼야 제대로 빠질 수 있음
        //심지어 이전에는 두 while문 앞에 반복해서 넣음으로써 코드 중복도 있었고 아무튼 비효율적
    }
    cout << cnt;
}
