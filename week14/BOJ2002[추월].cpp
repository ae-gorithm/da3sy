#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<string, int> carIn;
    string carOut[n];
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        carIn[s] = i;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> carOut[i];
    }
    for(int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++) {
            if (carIn[carOut[j]] < carIn[carOut[i]]) {
                cnt++;
                break;
            }
        }
    }
    cout << cnt;
}
