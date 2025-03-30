#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n, tapeLength;
    cin >> n >> tapeLength;
    
    int hole[n];
    for (int i = 0; i < n; i++) {
        cin >> hole[i];
    }
    
    sort(hole, hole+n);
    
    int cnt = 1;
    int currMin = hole[0];
    for (int i = 0; i < n; i++) {
		if (hole[i] - currMin >= tapeLength) {
			      cnt++;
            currMin = hole[i];
		    }
    }
    cout << cnt;
}
