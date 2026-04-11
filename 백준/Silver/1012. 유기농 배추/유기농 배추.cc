#include <iostream>
#include <queue>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int t, n, m, k;
int land[52][52];
bool visited[52][52];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (!visited[nx][ny] && land[nx][ny] == 1) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int main() {
    cin >> t;
    for (int test_case = 0; test_case < t; test_case++) {
        int sworm = 0;
        for (int i = 0; i < 52; i++) {
            fill(land[i], land[i] + 52, 0);
            fill(visited[i], visited[i] + 52, false);
        }

        cin >> n >> m >> k;
        int x, y;
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            land[x][y] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && land[i][j] == 1) {
                    bfs(i, j);
                    sworm++;
                }
            }
        }
        cout << sworm << "\n";

    }

    return 0;
}