#include <iostream>

using namespace std;

int n;
int home[18][18];
int ans = 0;

// dir 정의 -> 가로: 0, 세로: 1, 대각선: 2
void dfs(int r, int c, int dir) {

    if (r == n && c == n) {
        ans++;
        return;
    }

    // 다음에 가로로 이동
    if (dir == 0 || dir == 2) {
        if (c + 1 <= n && home[r][c + 1] == 0) {
            dfs(r, c + 1, 0);
        }
    }

    // 다음에 세로로 이동
    if (dir == 1 || dir == 2) {
        if (r + 1 <= n && home[r + 1][c] == 0) {
            dfs(r + 1, c, 1);
        }
    }

    // 다음에 대각선 방향으로 이동
    if (r + 1 <= n && c + 1 <= n) {
        if (home[r + 1][c] == 0 && home[r][c + 1] == 0 && home[r + 1][c + 1] == 0) {
            dfs(r + 1, c + 1, 2);
        }
    }

}

// int dp[18][18][3];

// dp 풀이
// int main() {
//     cin >> n;

//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= n; j++) 
//             cin >> home[i][j];
//     }

//     dp[1][2][0] = 1;
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= n; j++) {
//             if (home[i][j] == 1) continue;

//             dp[i][j][0] += (dp[i][j - 1][0] + dp[i][j - 1][2]);

//             dp[i][j][1] += (dp[i - 1][j][1] + dp[i - 1][j][2]);

//             if (home[i - 1][j] != 1 && home[i][j - 1] != 1) {
//                 dp[i][j][2] += (dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2]);
//             }
//         }
//     }

//     cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];


//     return 0;
// }

int main() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) 
            cin >> home[i][j];
    }

    if (home[n][n] == 1) {
        cout << 0;
        return 0;
    }

    dfs(1, 2, 0);
    cout << ans;

    return 0;
}