// 8/6(수) 13:04 ~ 13:20 (16분)
// 13:08 시간 초과 - n, m 십만 -> 2중 for문 안 됨
#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); //얘도 추가해야 시간 초과 안 나는 듯
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int arr[n+1]; //sum[0] = 0을 위해 n+1로 정의
    int sum[n+1];
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i]; //sum[0] 없이 if-else도 시간 초과 남
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << sum[b] - sum[a-1] << "\n";
    }
}
