// 백준 2579번 두번째 풀이, 아이디어: 밟지 않을 게단 점수의 합의 최솟값을 구한다
#include <iostream>

using namespace std;

int n;
int d[301];
int s[301];

int main() {

    cin >> n;
    int total = 0;

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        total += s[i];
    }

    d[1] = s[1]; d[2] = s[2]; d[3] = s[3];

    for (int i = 4; i <= n - 1; i++) {
        d[i] = min(d[i - 2], d[i - 3]) + s[i];
    }

    cout << total - min(d[n - 1], d[n- 2]);

    return 0;
}