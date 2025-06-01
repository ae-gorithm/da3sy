#include<iostream>
#include<stack>
using namespace std;

double cal(double a, double b, char c) {
    if (c == '+') {
        return a + b;
    } else if (c == '-') {
        return a - b;
    } else if (c == '*') {
        return a * b;
    } else {
        return a / b;
    }
}

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    stack<double> s;
    int alpha[27] = {0, };
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            int num;
            if (alpha[str[i]- 'A'] == 0) {
                cin >> num;
                alpha[str[i] - 'A'] = num;
                n--;
            } else {
                num = alpha[str[i]-'A'];
            }
            s.push((double)num);
        } else {
            double next = s.top(); s.pop();
            double first = s.top(); s.pop();
            s.push(cal(first, next, str[i]));
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << s.top();
}

// 소수점 아래 개수 설정하기
// cout << fixed
// cout.precision(개수)
// cout << fixed 안 하면 자연수 부분을 포함한 숫자의 개수가 됨

//아놀디의 아스키코드를 이용하라는 말 덕분에 금방 해결할 수 있었다.
//알파벳의 인덱스를 아스키코드로 하자 -> 알파벳 - 'A' : 인덱스로 설정하는 생각을 할 수 있었음
//처음에는 스택에 넣는 숫자를 n을 컨트롤하려 해서 예외가 발생 - 한 번 틀리고 해결
