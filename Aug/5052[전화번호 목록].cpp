#include<iostream>
#include<algorithm>
using namespace std;

// 8/7(목) 12:57 ~ 13:20 (23분)
// 1차 : 10% 시간 초과
// 2차 : 성공! / 정렬을 하면 굳이 전체 순회할 필요 없이 전 것보다 긴 것 당연한 상태에서 전 요소로 시작하는지만 확인하면 되니까 귯
// js에서는 startsWith라를 함수가 있어서 c++에서는 어떤 게 그 기능을 하나 찾아봄 -> rfind() 반환값이 0이면 0번째에서 시작한다는 뜻

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        string s[n];
        for (int j = 0; j < n; j++) cin >> s[j];
        sort(s, s+n);
        bool flag = true;
        for (int j = 1; j < n; j++) {
            if (s[j].rfind(s[j-1],0) == 0) {
                flag = false;
                break;
            }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
}
