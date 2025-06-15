#include<iostream>
#include<set>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n1, n2;
    cin >> n1 >> n2;
    set<int> s;
    int cnt = 0;
    for (int i = 0; i < n1 + n2; i++) {
        int a;
        cin >> a;
        if (s.find(a) == s.end()) {
            s.insert(a);
        } else {
            cnt++;
        }
    }
    cout << s.size() - cnt;
}
