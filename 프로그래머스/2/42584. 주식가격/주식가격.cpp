#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n, 0);
    
    stack<int> st;
    for (int i = 0; i < prices.size(); i++) {
        // 가격이 떨어졌으면, 그 시점을 저장
        while (!st.empty() && prices[st.top()] > prices[i]) {
            answer[st.top()] = i - st.top();
            st.pop();
        }
            
        st.push(i);
    }
    
    while (!st.empty()) {
        answer[st.top()] = n - st.top() - 1;
        st.pop();
    }
    
    return answer;
}