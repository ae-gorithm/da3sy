// 8/4 14:13 ~ 14:33

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n+1, 0);
    for (int i = 2; i < n+1; i++) {
        if (i % 2 == 0 && i % 3 == 0) {
            arr[i] = min({arr[i/2], arr[i/3], arr[i-1]}) + 1;
            continue;
        } 
        if (i % 2 == 0) {
            arr[i] = min(arr[i/2], arr[i-1]) + 1;
            continue;
        }
        if (i % 3 == 0) {
            arr[i] = min(arr[i/3], arr[i-1]) + 1;
            continue;
        }
        arr[i] = arr[i-1] + 1;
    }
    cout << arr[n];
}

//dp라 해서 top-down, down-up으로 해야 할지 바로 생각하게 되는 시야가 생김을 느낌
// 10의 6승이기 때문에 인덱스 처음붕터 O(n)으로 탐색해도 되겠다고 우선 생각하고 1중 for문으로 할 수 있는 방법을 생각함
//dp는 일반적으로 bottom-up일 때 이전 값들 중 최대나 최소를 가져올 때 특정 범위나 특정 값들 중 골라서 가져오는 경우가 많음
