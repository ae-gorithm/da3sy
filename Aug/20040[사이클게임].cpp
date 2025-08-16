// 8/16 (토) 17:24 ~ 18:25
// 처음에 dfs로 접근하다가 visited로 안 되길래 unioin find로 접근
// 근데 unite -> find 아니고 find -> unite인데 유니온파인드 로직 이해를 좀 해야 하지 않을까;;

#include<iostream>
#include<vector>
using namespace std;

int parent[500000];

int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) parent[a] = b; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
        if (find(a) == find(b)) { //둘이 같은 집합이니?
            cout << i+1;
            return 0;
        }
        unite(a, b); //둘이 같은 집합 아니니까 합쳐
	}
    cout << 0;
}
