#include <iostream>
#include <stack>
using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1이 파란 칸, 0이 빨간 칸에 대응

bool vis[502][502]; // 해당 칸을 방문했는지 여부를 저장
int n = 7, m = 10; // n = 행의 수, m = 열의 수
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 상하좌우 네 방향을 의미

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<pair<int, int>> st;
    vis[0][0] = true;
    st.push({0, 0}); // 시작점을 큐와 방문 표시에 넣음

    while (!st.empty()) {
        auto curr = st.top();
        st.pop();
        cout << '(' << curr.X << ", " << curr.Y << ") -> ";

        for (int dir = 0; dir < 4; dir++) {
            int nx = curr.X + dx[dir];
            int ny = curr.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] == true || board[nx][ny] == 0) continue;

            vis[nx][ny] = 1;
            st.push({nx, ny});
        }
    }

}