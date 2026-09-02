#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int mod = 1000000007;
    
    vector<vector<int>> dp(n, vector<int>(m, 0));
    vector<vector<bool>> water(n, vector<bool>(m, false));
    
    for (auto puddle: puddles) {
        water[puddle[1] - 1][puddle[0] - 1] = true;
    }
    

    dp[0][0] = 1;    
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (water[i][j]) continue;
            
            if (i > 0) {
                dp[i][j] += dp[i - 1][j];
            }
            
            if (j > 0) {
                dp[i][j] += dp[i][j - 1];
            }
            
            dp[i][j] %= mod;
        }
    }
    
    answer = dp[n - 1][m - 1];
    return answer;
}