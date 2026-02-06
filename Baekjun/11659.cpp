#include <iostream>

using namespace std;

int n, m;
int a[100001];
long long d[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    d[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = d[i - 1] + a[i];
    }

    while (m--) {
        int st, en;
        cin >> st >> en;
        cout << d[en] - d[st - 1] << '\n';
    }
    return 0;
}
