#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n], sum[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum[i] = arr[i];
    }

    int ans = sum[0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
                sum[i] = max(sum[i], sum[j] + arr[i]);
            }
        }
        ans = max(ans, sum[i]);
    }

    cout << ans;
}

// DP인 거는 대애충 초장에 파악을 했는데 1시간동안 모르겠어서 그냥 인터넷 찾아봄
// 너무 복잡하게 생각하고 있었다...~~


//첫 시도 반례1
//5
//3 2 2 4 5
