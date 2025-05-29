#include<iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int temp[n];
    int sumN = n-k+1;
    int sumTemp[sumN] = {0, };
    for (int i = 0; i < n; i++) {
        cin >> temp[i];
    }
    int max = -10000000;
    for (int i = 0; i < sumN; i++) {
        for (int j = i; j < k+i; j++) {
            sumTemp[i] += temp[j];
        }
        if (sumTemp[i] > max) max = sumTemp[i];
    }
    cout << max;
}
