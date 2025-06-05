#include<iostream>
#include<algorithm>
using namespace std;

int secondBig(int a, int b, int c, int d) {
    int arr[4];
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    arr[3] = d;
    sort(arr, arr+4);
    return arr[2];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    int poll[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> poll[i][j];
        }
    }
    while (n > 1) {
        for (int i = 0; i < n; i+=2) {
            for (int j = 0; j < n; j+=2) {
                int val = secondBig(poll[i][j], poll[i][j+1], poll[i+1][j], poll[i+1][j+1]);
                poll[i/2][j/2] = val;
            }
        }
        n /= 2;
    }
    cout << poll[0][0];
}
