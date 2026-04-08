#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[50002];

int main() {
    cin >> n;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        int min_val = 50002;
        for (int j = 1; j * j <= i; j++) {
            min_val = min(min_val, dp[i - j * j]);
        }
        dp[i] = min_val + 1;
    }

    cout << dp[n];

    return 0;
}