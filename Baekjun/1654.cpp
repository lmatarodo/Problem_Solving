#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int n, k;
int lanton[10002];

bool solve(ll x) {
    ll cur = 0; // 현재 랜선의 길이로 만들어지는 랜턴의 갯수
    for (int i = 0; i < k; i++) {
        cur += lanton[i] / x;
    }
    return cur >= n; // 현재 랜선의 길이로 만들어지는 랜선의 갯수가 n개를 넘는지를 반환
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k >> n;
    for (int i = 0; i < k; i++) cin >> lanton[i];

    ll st = 1;
    ll en = (1ll << 31) - 1;
    ll ans = 0;

    while (st <= en) {
        ll mid = (st + en) / 2;
        if (solve(mid)) { 
            ans = mid; // 일단 조건을 만족하므로 정답 후보에 저장
            st = mid + 1; // 더 긴 길이가 가능한지 확인하기 위해 오른쪽 탐색
        }
        else en = mid - 1; // 너무 길어서 n개를 만들지 못하므로 왼쪽 탐색
    }
    cout << ans;

    return 0;
}
