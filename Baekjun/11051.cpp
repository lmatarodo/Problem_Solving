#include <iostream>

using namespace std;

int dp[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1; dp[i][i] = 1; // 모든 n에 대해 nC0 = 1, nCn = 1임을 미리 깔끔하게 초기화
        for (int j = 1; j < i; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
        }
    }
    cout << dp[n][k];
    return 0;
}
