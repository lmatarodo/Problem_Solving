#include <string>
#include <stack>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(s[i]);
        }
        
        else if (s[i] == ')') {
            if (st.empty()) {
                answer = false;
                return answer;
            }
            
            else {
                st.pop();
            }
        }
    }
    
    if (!st.empty()) answer = false;
    return answer;
}