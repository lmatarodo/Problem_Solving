#include <iostream>
#include <stack>

using namespace std;

int main() {
    string s;
    stack<char> st;
    cin >> s;

    int count = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') st.push(s[i]);

        else if (s[i] == ')' && s[i - 1] == '(') {
            st.pop();
            count += st.size();
        }

        else if (s[i] == ')' && s[i - 1] == ')') {
            st.pop();
            count++;
        }

    }

    cout << count;
    return 0;
}