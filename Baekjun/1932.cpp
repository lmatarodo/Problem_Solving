#include <iostream>
#include <algorithm>

using namespace std;

int n;
int triangle[502][502];
int dp[502][502];

int main() {

    cin >> n;
    int max_val = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];

            if (i == 0) {
                dp[i][j] = triangle[0][0];
            }
            else if (i == 1) {
                dp[i][j] = dp[0][0] + triangle[i][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
            max_val = max(dp[i][j], max_val);
        }
    }

    cout << max_val;

    return 0;
}