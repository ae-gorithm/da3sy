#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int tree[n];
    int right = 0;
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
        right = max(tree[i], right);
    }
    int left = 1;
    int mid = (right + left) /2;
    int ans = 0;
    while(left <= right) { //얘도 < 안 됨 / 같을 때까지 확인해야 함
        long long sum = 0; //int 안 됨 -> 3차 시도 정답 항상 int 오버플로우를 생각하자!
        for (int i = 0; i < n; i++) {
            sum += tree[i] - mid < 0 ? 0 : tree[i] - mid; //0보다 작을 때는 더하면 안 되고 그냥 더하면 안 돼서 삼항 연산자 추가
        }
        if (sum < m) {
            right = mid-1;
        } else {
            ans = mid;
            left = mid + 1;
        }
        mid = (right + left) / 2;
    }
    cout << ans;
}

//1차 시도 2% 틀림
//2차 시도 2% 틀림
//이분 탐색 혼자 틀 짰다는 것에 성장 의의를 둔다..!
