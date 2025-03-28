#include<iostream>
using namespace std;

int cnt= 0;
int n;
char arr[51][51];

void checkI() {
	for (int i = 0; i < n; i++) {
		int tmp = 1;
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == arr[i][j+1]) {
				tmp++;
			} else {
				if (tmp > cnt) cnt = tmp;
				tmp = 1;
			}
		}
	}
}

void checkJ() {
	for (int j = 0; j < n; j++) {
		int tmp = 1;
		for (int i = 0; i < n; i++) {
			if (arr[i][j] == arr[i+1][j]) {
				tmp++;
			} else {
				if (tmp > cnt) cnt = tmp;
				tmp = 1;
			}
		}
	}
}

void swapJ(int x, int y) {
    if (y == n-1) return;
    char tmp = arr[x][y];
    arr[x][y] = arr[x][y+1];
    arr[x][y+1] = tmp;
}

void swapI(int x, int y) {
    if (x == n-1) return;
    char tmp = arr[x][y];
    arr[x][y] = arr[x+1][y];
    arr[x+1][y] = tmp;
}

int main() {
    cin >> n;
    for (int i =0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            swapJ(i, j);
            checkI();
            checkJ();
            swapJ(i, j);
            
            swapI(i, j);
            checkI();
            checkJ();
            swapI(i, j);
        }
    }
    cout << cnt;
}
