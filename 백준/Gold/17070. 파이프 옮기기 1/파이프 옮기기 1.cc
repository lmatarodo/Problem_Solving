#include <iostream>

using namespace std;

int n;
int home[18][18];
int dp[18][18][3];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) 
            cin >> home[i][j];
    }

    dp[1][2][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (home[i][j] == 1) continue;

            dp[i][j][0] += (dp[i][j - 1][0] + dp[i][j - 1][2]);

            dp[i][j][1] += (dp[i - 1][j][1] + dp[i - 1][j][2]);

            if (home[i - 1][j] != 1 && home[i][j - 1] != 1) {
                dp[i][j][2] += (dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2]);
            }
        }
    }

    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];


    return 0;
}