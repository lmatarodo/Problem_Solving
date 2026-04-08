#include <iostream>
#include <stack>

using namespace std;

int n;
int h[80002];

int main() {
    long long answer = 0;
    cin >> n;
    stack<int> st;
    for (int i = 0; i < n; i++) 
        cin >> h[i];
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() <= h[i]){
            st.pop();
        }
        answer += st.size();
        st.push(h[i]);
    }
    cout << answer;
    return 0;
}