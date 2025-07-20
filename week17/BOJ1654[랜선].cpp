#include<iostream>
using namespace std;

int main() {
    int k, n;
    cin >> k >> n;
    int max = 0;
    int line[k];
    for (int i =0 ; i < k; i++) {
        cin >> line[i];
        if (max == 0 || max < line[i]) max = line[i];
    }
    long long left = 1, right = max;
    long long mid = (left + right) / 2;
    while (left <= right) {
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            cnt += line[i]/ mid;
        }
        if (cnt >= n) left = mid + 1;
        else right = mid-1;
        mid = (left + right) / 2;
    }
    cout << mid;
}

//47% 틀림 -> left, mid : long long으로 변경하여 성공
