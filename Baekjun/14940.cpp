#include <iostream>
#include <queue>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int n, m;
int map[1002][1002];
int dist[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    dist[x][y] = 0;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (map[nx][ny] == 1 && dist[nx][ny] == -1) {
                q.push({nx, ny});
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            }
        }
    }

}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        fill(dist[i], dist[i] + m, -1);
    
    pair<int, int> arrival;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) arrival = {i, j};
        }
    }

    bfs(arrival.X, arrival.Y);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) cout << "0 "; // 원래 갈 수 없는 땅
            else if (map[i][j] == 1 && dist[i][j] == -1) cout << "-1 ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}