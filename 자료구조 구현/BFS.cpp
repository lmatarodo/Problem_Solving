#include <iostream>
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
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> q;
    vis[0][0] = 1; 
    q.push({0 , 0}); // 시작하는 칸을 큐에 넣고 방문했다는 표시를 남김

    while (!q.empty()) {
        pair<int, int> curr = q.front(); // 큐에서 원소 칸 하나를 꺼냄
        q.pop(); // 꺼낸 칸을 pop
        cout << '(' << curr.X << ", " << curr.Y << ") -> ";
        for (int dir = 0 ; dir < 4; dir++) {
            int nx = curr.X + dx[dir];
            int ny = curr.Y + dy[dir]; // 인접하는 칸으로 이동

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 조건을 만족하는지 확인
            if (vis[nx][ny] == 1 || board[nx][ny] == 0) continue; // 이미 방문한 칸이거나 빨간 칸이면 건너뜀

            vis[nx][ny] = 1;
            q.push({nx, ny}); // 방문했다는 표시를 남기고 해당 칸을 큐에 삽입
        }

    }

}