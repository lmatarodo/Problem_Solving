#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> st; // 보조 컨테이너
    
    int currentbox = 1; // 보조 컨테이너에 들어가 있는 최대 번호
    
    for (int i = 0; i < order.size(); i++) {
        while (currentbox <= order[i]) {
            st.push(currentbox);
            currentbox++;
        }
                
        if (!st.empty() && st.top() == order[i]) {
            answer++;
            st.pop();
        }
        else break;
    }
    
    return answer;
}