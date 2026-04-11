#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int s[22][22];
bool isused[22];
int min_diff = 1e9;

void func(int curr, int cnt) { // n개 중 n / 2개의 사람들을 선택해서 팀을 만듬
    if (cnt == n / 2) {
        int stark_score = 0;
        int link_score = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++){
                if (isused[i] && isused[j]) stark_score += s[i][j];
                if (!isused[i] && !isused[j]) link_score += s[i][j];
            }
        }

        int diff = abs(stark_score - link_score);
        if (diff < min_diff) min_diff = diff;
        return;
    }

    for (int i = curr; i < n; i++) {
        if (!isused[i]) {
            isused[i] = true;
            func(i + 1, cnt + 1);
            isused[i] = false;
        }
    }

}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }
    func(0, 0);
    cout << min_diff;

    return 0;
}