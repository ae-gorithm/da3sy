#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//이분 그래프 이웃한 정점이 서로 다른 색상으로 칠해질 수 있는 그래프

int main() {
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) { //케이스 개수만큼 순회
        int u,v;
        cin >> u >> v;
        vector<int> vec[u+1];
        int colors[u+1] = {0,};
        bool isB = true;
        
        //그래프 할당
        for (int j = 0; j < v; j++) {
            int a, b;
            cin >> a >> b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        
        queue<int> q;
        //색상 바꿔가면서 BFS 탐색하기
        for (int j = 1; j < u+1; j++) {
            if (!isB) break;
            if (colors[j] == 0) {
                //BFS
                q.push(j);
                colors[j] = 1;
                while(!q.empty() && isB) {
                    int a = q.front();
                    q.pop();
                    for (int t = 0; t < vec[a].size(); t++) {
                        if (colors[vec[a][t]] == 0) {
                            q.push(vec[a][t]);
                            colors[vec[a][t]] = colors[a] * -1;
                        } else if (colors[vec[a][t]] + colors[a] != 0){
                            isB = false;
                            break;
                        }
                    }
                 }
            }
        }
        
        //이분그래프인지 아닌지 출력
        cout << (isB ? "YES" : "NO") <<"\n";
    }
}
