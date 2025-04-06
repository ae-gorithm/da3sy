//근데 사실 이미 풀려있었음...ㅎㅎ

#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0); //1. 시간 초과 -> 코드 추가
    cin.tie(NULL);
    int m, h;
    cin >> m >> h;
    int tree[m];
    for (int i = 0; i < m; i++) 
        cin >> tree[i];
    sort(tree, tree+m);
    int low = 0, high = tree[m-1], mid, len;
    //첫 채점 전 예제 5을 통해 low 값을 tree[0]이 아닌 0으로 수정
    while (low <= high && low >= 0) {
        long long sum = 0; //2. 틀렸습니다 -> 자료형 수정
        mid = (low + high) / 2;
        for (int i = 0; i < m; i++) {
            if (mid < tree[i]) {
                sum += tree[i] - mid;
            }
        }
        if (sum >= h) { //3. 틀렸습니다 -> 왜지.. 근데 여기 문제는 맞음
            low = mid + 1; //4. 시간초과 -> 아니 미띤넘ㅇ 둘다 -1 함 ㄷㄷ
            len = mid;
        }
        else high = mid - 1;
    }
    cout << len << "\n";
}
