// 8/4 13:08 ~ 14:07

//1차 시도 13:20 첫 완성
#include<iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a>> b >> c;
    int num = 1; //-> long long
    for(int i = 0; i < b; i++) {
        num *= a;
        num %= c;
    }
    cout << num;
}
// 근데 우선 시간 초과 날 걸 알긴 함 그래서 안 돌렸음
// 지수 b에 대한 횟수를 줄여야 함 -> 분할 정복 적용

#include<iostream>
using namespace std;

long long a, b, c;
long long cal(long long x) {
    if (x == 0) return 1;
    long long half = cal(x/2);
    if (x%2 == 0) return (cal(x/2) * cal(x/2)) % c;
    else return (cal(x/2) * cal(x/2))%c * a%c; //(cal(x/2) * cal(x/2) * a)%c; 이렇게 되는 순간 틀림 cal(x/2)의 결과를 a와 마음대로 곱하는 걸로 합치면 안 됨
}

int main() {
    cin >> a>> b >> c;
    long long num = cal(b);
    cout << num;
}

//분할 정복 + 모듈로 연산
// (a*b) % c = a%c * b%c
