#include<iostream>
#include<vector>
using namespace std;

int main() {
    int max = 1299709;
    int arr[100000];
    vector<bool> v(max + 1, true);
    for (int i = 2; i * i <= max; i++) {
        if (v[i]) {
            for (int k = i * i; k <= max; k += i) {
                v[k] = false;
            }
        }
    }
    int index = 0;
    for (int i = 2; i < max+1; i++) {
        if (v[i]) {
            arr[index] = i;
            index++;
        }
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int num;
        cin >> num;
        for (int j = 0;; j++) {
            if (arr[j] < num) continue;
            if (arr[j] == num) {
                cout << 0 << "\n";
                break;
            }
            cout << arr[j] - arr[j-1] << "\n";
            break;
        }
    }
}
