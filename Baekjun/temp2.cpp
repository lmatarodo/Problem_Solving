#include <iostream>
#include <queue>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int n;
char board[102][102];
bool visited[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y, char c) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (visited[nx][ny] || board[nx][ny] != c) continue;
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
}

int main() {

    cin >> n;
    string ipt;

    for (int i = 0; i < n; i++) {
        cin >> ipt;
        for (int j = 0; j < n; j++)
            board[i][j] = ipt[j];
    }

    int fcnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                bfs(i, j, board[i][j]);
                fcnt++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        fill(visited[i], visited[i] + n, false);
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'G') board[i][j] = 'R';
        }
    }

    int scnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                bfs(i, j, board[i][j]);
                scnt++;
            }
        }
    }    

    cout << fcnt << " " << scnt;

    return 0;
}