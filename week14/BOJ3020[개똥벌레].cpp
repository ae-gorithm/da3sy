//메모리 초과
//물론 메모리 초과 안 나도 시간 초과 나겠지

#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, h;
    cin >> n >> h;
    vector<vector<bool> > gool(n, vector<bool>(h, false));
    for (int i = 0; i < n; i++) {
        int height;
        cin >> height;
        for (int j = 0; j < height; j++) {
            if (i %2 == 0) {
                gool[i][j] = true;
            } else {
                gool[i][h-j-1] = true;
            }
        }
    }
    int min = -1;
    int minCnt = 0; //구간 수
    int cnt = 0; //최소 장애물 수
    for (int i = 0; i < h; i++) {
        cnt = 0;
        for (int j = 0; j < n; j++) {
            if (gool[j][i]) {
                cnt++;
            }
        }
        if (min == -1 || min > cnt) {
            minCnt = 1;
            min = cnt;
        } else if (min == cnt) {
            minCnt++;
        }
    }
    cout << min << " " << minCnt;
}
