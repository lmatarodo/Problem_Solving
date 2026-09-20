#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int n = money.size();
    vector<int> dp1(n, 0); vector<int>dp2(n, 0);
    
    // 첫번째 집을 턴다고 가정 -> 마지막 집은 못 털음
    dp1[0] = money[0]; dp1[1] = money[0];
    for (int i = 2; i < n - 1; i++) {
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + money[i]);
    }
    
    // 마지막 집을 턴다고 가정 -> 첫번째 집은 못 털음
    dp2[1] = money[1];
    for (int i = 2; i < n; i++) {
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + money[i]);
    }
    answer = max(dp1[n - 2], dp2[n - 1]);
    
    return answer;
}