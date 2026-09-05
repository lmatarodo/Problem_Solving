#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    
    long long sum1 = 0, sum2 = 0;
    queue<long> q1; queue<long> q2;
    
    for (int i: queue1) {
        q1.push(i);
        sum1 += i;
    }
    
    for (int i: queue2) {
        q2.push(i);
        sum2 += i;
    }
    
    int cnt = 0;
    int n = q1.size();
    
    while (cnt <= 4 * n) {
        if (sum1 < sum2) {
            long cur = q2.front();
            sum1 += cur; sum2 -= cur;
            q1.push(cur); q2.pop();
        }
        
        else if (sum1 > sum2) {
            long cur = q1.front();
            sum1 -= cur; sum2 += cur;
            q2.push(cur); q1.pop();
        }
        
        else if (sum1 == sum2) break;
        cnt++;
    }
    if (cnt == 4 * n + 1) answer = -1;
    else answer = cnt;
    return answer;
}