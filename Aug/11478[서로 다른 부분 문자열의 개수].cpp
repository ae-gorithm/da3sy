// 8/13(수) 13:55 ~ 
// (분류 봄) 집합!! 을 떠올리자. - 그래도 잘 모르겠음
// 뭐지.. 왜 못 떠올린 거지..;;

#include<iostream>
#include<unordered_set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    unordered_set<string> us;
    for (int i = 0; i < s.length(); i++) {
        string tmp;
        for (int j = i; j < s.length(); j++) {
            tmp += s[j];
            us.insert(tmp);
        }
    }
    cout << us.size();
}

