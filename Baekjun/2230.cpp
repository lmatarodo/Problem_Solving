#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    int ans = (1ll << 31) - 1;

    for (int i = 0; i < n; i++) {
        int up_idx = lower_bound(a.begin(), a.end(), a[i] + m) - a.begin(); // 현재 보고 있는 값의 +m 이상보다 크거나 같은 수가 처음으로 등장하는 인덱스
        if (up_idx < n) // up_idx가 n을 초과하지 않는 범위 안에서만
            ans = min(ans, a[up_idx] - a[i]); // 최솟값 업데이트
    }
    
    cout << ans;

    return 0;
}
