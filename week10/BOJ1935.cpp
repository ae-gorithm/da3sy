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
