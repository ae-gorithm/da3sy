#include<iostream>
using namespace std;

int main() {
    int t;
    cin >>t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int arr[n];
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        int max = -1000000;
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = j; k < n; k++) {
                sum += arr[k];
                if (sum > max) max = sum;
            }
        }
        cout << max << "\n";
    }
}
