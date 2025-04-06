#include<iostream>
#include<queue>
using namespace std;

int main() {
    int tests;
    cin >> tests;
	
    for (int i = 0; i < tests; i++) {
        int n, m;
        cin >> n >> m;
		
		queue<pair<int, int>> q;
		priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            q.push({num, i});
			pq.push(num);
        }
		
		int cnt = 1;
        while(1) {
			if (pq.top() != q.front().first) {
				int a = q.front().first;
				int b = q.front().second;
				q.pop();
				q.push({a,b});
				continue;
			} else {
				if (q.front().second == m) break;
				q.pop();
				pq.pop();
				cnt++;
			}
        }
        cout << cnt << "\n";
    }
}
