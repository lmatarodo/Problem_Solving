#include <iostream>
#include <stack>

using namespace std;

int main() {


    while (true) {
        string s;
        stack<char> st;
        bool flag = true;
        getline(cin, s);

        if (s == ".") break; // 종료 조건

        for (auto c : s) {
            if (c == '(' || c == '[') {
                st.push(c); // 개괄호일 경우에 스택에 삽입
            }
            else if (c == ')') { // 첫번째 닫는 괄호일 경우,
                if (st.empty() || st.top() != '(') { // 스택이 비어있거나 짝이 맞지 않는 경우에는
                    cout << "no\n"; // 균형 있는 문자열이 아니다.
                    flag = false;
                    break;
                }
                st.pop();
            }

            else if (c == ']') { // 두번째 닫는 괄호일 경우,
                if (st.empty() || st.top() != '[') { // 스택이 비어있거나 짝이 맞지 않는 경우에는
                    cout << "no\n"; // 균형 있는 문자열이 아니다.
                    flag = false;
                    break;
                }
                st.pop();
            }    
        }

        if (flag && st.empty()) cout << "yes\n";
        else if (flag && !st.empty()) cout << "no\n";
    }
    return 0;
}