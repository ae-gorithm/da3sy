#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int s[n];
    unordered_map<int, int> fruit;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int left = 0, right = 0, max = 0;
    while(right < n) {
        fruit[s[right]]++;
        while(fruit.size() > 2) {
            fruit[s[left]]--;
            if (fruit[s[left]] == 0) fruit.erase(s[left]);
            left++;
        }
        max = max > right - left + 1 ? max : right - left + 1;
        right++;
    }
    cout << max;
}

//TC1
//left = 0, right = 0, max = 0
//[5], fruit[5] = 1, fruit.size() = 1, max =1, right = 1
//[5, 1] fruit[5] = 1, fruit[1] = 1, fruit.size() = 2, max = 2, right = 2
//[5, 1, 1] fruit[5] = 1, fruit[1] = 2, fruit.size() = 2, max = 3, right = 3
//[5, 1, 1, 2] fruit[5] = 1, fruit[1] = 2, fruit[2] = 1, fruit.size() = 3, -> while문 첫 진입, 5 빠짐, left = 1, max = 3, right = 4
//[1, 1, 2, 1] fruit[1] = 3, fruit[2] = 1, fruit.size() = 2, -> while문 안 들어감, left = 1, max = 4, right = 5 - 바깥 while문 끝
