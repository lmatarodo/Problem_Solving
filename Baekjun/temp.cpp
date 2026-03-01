#include <iostream>
#include <algorithm>

using namespace std;

int n;
const int INF = 1e7;
int dp[100002];

int main() {
  cin >> n;

  for (int i = 2; i <= n; i++) {
    int d1 = dp[i - 1] + 1; int d2 = INF; int d3 = INF;
    if (i % 2 == 0)
      d2 = dp[i / 2] + 1;
    else if (i % 3 == 0)
      d3 = dp[i / 3] + 1;

    dp[i] = min({d1, d2, d3});
  }

  cout << dp[n];
}