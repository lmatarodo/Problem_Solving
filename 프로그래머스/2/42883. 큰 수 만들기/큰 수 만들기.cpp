#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<int> st;
    
    for (int i = 0; i < number.size(); i++) {
        while (!st.empty() && k > 0 && st.top() < int(number[i])) {
            st.pop();
            k--;
        }
        st.push(int(number[i]));
    }
    
    while (k > 0) {
        st.pop();
        k--;
    }
    
    while (!st.empty()){
        answer += char(st.top());
        st.pop();
    }
    reverse(answer.begin(), answer.end());
    return answer;
}