#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<int> st;
    
    for (int i = 0; i < prices.size(); i++) {
        int cnt = 0;
        for (int j = i; j < prices.size(); j++) {
            if (prices[i] > prices[j] || j == prices.size() - 1) {
                answer.push_back(cnt);
                cnt = 0;
                break;
            }
            cnt++;
        }
    }
    
    return answer;
}