#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<char> st;
    int temp = 1, answer = 0;
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            temp *= 2;
            st.push(s[i]);
        }

        else if (s[i] == '[') {
            temp *= 3;
            st.push(s[i]);
        }

        else if (s[i] == ')') {
            if (st.empty() || st.top() != '(') {
                cout << "0";
                return 0;
            }

            if (s[i - 1] == '(') {
                answer += temp;
                temp /= 2;
                st.pop();
            }
            
            else if (s[i - 1] != '('){
                temp /= 2;
                st.pop();
            }
        }

        else if (s[i] == ']') {
            if (st.empty() || st.top() != '[') {
                cout << "0";
                return 0;
            }

            if (s[i - 1] == '[') {
                answer += temp;
                temp /= 3;
                st.pop();
            }
            
            else if (s[i - 1] != '['){
                temp /= 3;
                st.pop();
            }
        }
    }
    if (!st.empty()) { cout << "0"; return 0;}
    cout << answer;

    return 0;
}