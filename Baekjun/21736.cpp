#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

int n, m;
char campus[602][602];
bool visited[602][602];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin >> n >> m;

    queue<pair<int, int>> q;
    string col;
    for (int i = 0; i < n; i++) {
        cin >> col;
        for (int j = 0; j < m; j++) {
            campus[i][j] = col[j];
            if (campus[i][j] == 'I') {
                visited[i][j] = true;
                q.push({i, j});
            }
        }
    }

    int ans_cnt = 0;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (campus[nx][ny] == 'X' || visited[nx][ny]) continue;
            if (campus[nx][ny] == 'P') ans_cnt++;
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }

    if (ans_cnt == 0) cout << "TT";
    else cout << ans_cnt; 

    return 0;
}