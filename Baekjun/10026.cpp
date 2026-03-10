#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

int n;
char board[102][102];
bool visited[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    queue<pair<int, int>> q;

    cin >> n;
    string line;
    for (int i = 0; i < n; i++) {
        cin >> line;
        for (int j = 0; j < n; j++) 
            board[i][j] = line[j];
    }

    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) continue;
            cnt1++;
            q.push({i, j});
            visited[i][j] = true;
            char color = board[i][j];

            while (!q.empty()) {
                auto cur = q.front(); q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (visited[nx][ny] || color != board[nx][ny]) continue;

                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }

    // 보드 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
            if (board[i][j] == 'G') board[i][j] = 'R';
        }
    }

    int cnt2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) continue;
            cnt2++;
            q.push({i, j});
            visited[i][j] = true;
            char color = board[i][j];

            while (!q.empty()) {
                auto cur = q.front(); q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (visited[nx][ny] || color != board[nx][ny]) continue;

                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }

    cout << cnt1 << " " << cnt2;
    return 0;
}