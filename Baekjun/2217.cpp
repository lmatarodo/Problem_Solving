#include <iostream>
#include <algorithm>

using namespace std;

int n;
int w[100002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> w[i];

    sort(w, w + n, greater<int>());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, (i + 1) * w[i]);
    }

    cout << ans;

    return 0;
}
