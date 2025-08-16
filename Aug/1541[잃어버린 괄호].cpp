// 8/16 (토) 18:35 ~ 19:30
// 뭐지..;; 오늘 잘 안 풀리는 날인가

#include<iostream>
#include<queue>
#include<math.h>
using namespace std;

queue<char> q;

int calNum() {
    int n = q.size();
    int num = 0;
    while (n > 0) {
        n--;
        num += (q.front()-'0') * pow(10, n);
        q.pop();
    }
    return num;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int res = 0;
    bool oper = true;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            q.push(s[i]);
        }
        else {
            int num = calNum();
            if (oper) res += num;
            else res -= num;
            if (s[i] == '-') oper = false;
        }
    }
    if (oper) res += calNum();
    else res -= calNum();
    cout << res;
}
