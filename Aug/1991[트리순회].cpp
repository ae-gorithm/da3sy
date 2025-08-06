// 8/6 (수) 13:30 ~ 13:51
//pair 자료형 꼭 생각하기

#include<iostream>
using namespace std;

pair<char,char> alpha[27];

void pre(char curr) {
    if (curr == '.') return;
    cout << curr;
    pre(alpha[curr-'A'].first);
    pre(alpha[curr-'A'].second);
}

void inorder(char curr) {
    if (curr == '.') return;
    inorder(alpha[curr-'A'].first);
    cout << curr;
    inorder(alpha[curr-'A'].second);
}

void post(char curr) {
    if (curr == '.') return;
    post(alpha[curr-'A'].first);
    post(alpha[curr-'A'].second);
    cout << curr;
}


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char a, b, c;
        cin >> a >> b >> c;
        alpha[a-'A'].first = b;
        alpha[a-'A'].second = c;
    }
    pre('A');
    cout << "\n";
    inorder('A');
    cout << '\n';
    post('A');
}
