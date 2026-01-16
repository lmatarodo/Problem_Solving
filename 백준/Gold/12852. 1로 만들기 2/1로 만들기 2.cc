#include <iostream>
#include <algorithm>

using namespace std;

int n;
int d[1000001];
int pre[1000001]; // 이전 숫자가 무엇이었는지를 담아놓는 배열

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 2; i <= n; i++) {
        d[i] = d[i - 1] + 1;
        pre[i] = i - 1;
        if (i % 2 == 0 && d[i / 2] + 1 < d[i]) {
            d[i] = d[i / 2] + 1;
            pre[i] = i / 2;
        }
        if (i % 3 == 0 && d[i / 3] + 1 < d[i]) {
            d[i] = d[i / 3] + 1;
            pre[i] = i / 3;
        }
    }
    cout << d[n] << '\n';

    int idx = n;

    while (true) {
        cout << idx << ' ';
        if (idx == 1) break;
        idx = pre[idx];
    }


    return 0;
}
