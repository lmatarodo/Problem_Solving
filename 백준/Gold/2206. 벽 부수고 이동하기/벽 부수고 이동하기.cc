#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct State {
    int x, y, broken; // 0: 벽을 한 번도 안 부순 상태, 1: 벽을 한 번 부순 전적이 있는 상태
};

int n, m;
int map[1002][1002];
int dist[1002][1002][2];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y) {
    queue<State> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j][0] = -1;
            dist[i][j][1] = -1;
        }
    }

    q.push({x, y, 0});
    dist[x][y][0] = 1;


    while (!q.empty()) {
        State cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (map[nx][ny] == 0 && dist[nx][ny][cur.broken] == -1) { // 빈 칸을 만났을때,
                dist[nx][ny][cur.broken] = dist[cur.x][cur.y][cur.broken] + 1;
                q.push({nx, ny, cur.broken});
            }

            if (map[nx][ny] == 1) { // 벽을 만났을때,
                if (cur.broken == 0 && dist[nx][ny][1] == -1) { // 아직 벽을 부술 수 있는 상태 
                    dist[nx][ny][1] = dist[cur.x][cur.y][cur.broken] + 1;
                    q.push({nx, ny, 1});
                }
            }
        }
    }
}

int main() {

    cin >> n >> m;

    string line;
    for (int i = 0; i < n; i++) {
        cin >> line;
        for (int j = 0; j < m; j++) {
            map[i][j] = line[j] - '0';
        }
    }

    bfs(0, 0);
    int res1 = dist[n - 1][m - 1][0];
    int res2 = dist[n - 1][m - 1][1];
    if (res1 == -1 && res2 == -1) 
        cout << -1;
    
    else if (res1 == -1) 
        cout << res2;
    
    else if (res2 == -1) 
        cout << res1;
    
    else 
        cout << min(res1, res2);
    
    return 0;

}