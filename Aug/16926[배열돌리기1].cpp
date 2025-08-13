// 8/13(수) 14:34 ~ 15:53
// 로직을 생각해 냈다는 거에 그래도... 넘어가
// 중간중간 인덱스가 헷갈려서 tc2가 자꾸 안 넘어갔음
// 1차 : 11% 틀림
// 2차 : 29% 틀림 15:51
// 3차 : r 조건 수정 -> 시간복잡도 오류 날 것 같은데? -> 안 나네? ㅎ
// r 횟수 줄이는 방법 있을텐데 통과했으니까 그냥 넘어갈래

#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, r;
    cin >> n >> m>> r;
    int arr[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    while (r > 0) {
        r--;
        int tmp[n][m];
        int outerN = n;
        int outerM = m;
        int start = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tmp[i][j] = arr[i][j];
            }
        }
        while (outerN - start > 0 && outerM - start > 0) { // 2차 : 범위 변경
            for (int i = start; i < outerM-1; i++) {
                tmp[start][i] = arr[start][i+1];
            }
            for (int i = start; i < outerN-1; i++) {
                tmp[i][outerM-1] = arr[i+1][outerM-1];
            }
            for (int i = start + 1; i < outerN; i++) {
                tmp[i][start] = arr[i-1][start];
            }
            for (int i = start + 1; i < outerM; i++) {
                tmp[outerN-1][i] = arr[outerN-1][i-1];
            }
            outerN--;
            outerM--;
            start++;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = tmp[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
