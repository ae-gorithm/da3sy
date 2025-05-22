#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        string str = "-";
        for (int i = 0; i < n; i++) {
            string tmp = str;
            for (int j = 0; j < pow(3, i); j++) {
                str += " ";
            }
            str += tmp;
        }
        cout << str << "\n";
    }
}
