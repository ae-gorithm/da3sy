#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int max = 1000000;
    vector<bool> num(max+1, true);
    for (int i = 2; i*i <= max; i++) {
        if (num[i]) {
            for (int j = i*i; j <= max; j+=i) {
                num[j] = false;
            }
        }
    }
    vector<int> primeNum;
    for (int i = 3; i <= max; i++) {
        if (num[i]) primeNum.push_back(i);
    } //소수 찾기 끝

    while(1) {
        int input;
        cin >> input;
        if (input == 0) break;
        for (int i = 0; i < primeNum.size(); i++) {
            int sub = input - primeNum[i];
            if (binary_search(primeNum.begin(), primeNum.end(), sub)) {
                cout << input << " = " << primeNum[i] << " + " << sub << "\n";
                break;
            }
        }
    }
}
