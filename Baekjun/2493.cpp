#include <iostream>
#include <stack>

#define X first
#define Y second

using namespace std;

int n;
int height[500002]; // 탑들의 높이를 저장
int answer[500002];

int main() {

    cin >> n;
    stack<int> st; // 탑의 인덱스 번호
    for (int i = 0; i < n; i++) 
        cin >> height[i];

    for (int i = 0; i < n; i++) {
        while (!st.empty() && height[st.top()] < height[i]) {
            st.pop();
        }
        if (st.empty()) answer[i] = 0;
        else answer[i] = st.top() + 1;
        st.push(i);
    }

    for (int i = 0; i < n; i++)
        cout << answer[i] << " ";
    
    
    return 0;
}