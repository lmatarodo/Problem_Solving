#include <iostream>
#include <queue>

using namespace std;

int box[1002][1002];
int dist[1002][1002];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int n, m;
    cin >> m >> n;
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> box[i][j];
            if (box[i][j] == 1) 
                q.push({i, j}); // 각 시작점들을 모두 큐에 넣음            
            else if (box[i][j] == 0)
                dist[i][j] = -1; // 익지 않은 토마토 칸들은 모두 거리 -1로 초기화
        }   
    }

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = curr.first + dx[dir];
            int ny = curr.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (box[nx][ny] != 0 || dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[curr.first][curr.second] + 1;
            box[nx][ny] = 1;
            q.push({nx, ny});
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] == -1) {
                cout << "-1";
                return 0;
            }
            if (count <= dist[i][j]) count = dist[i][j];
        }
    }

    cout << count;

    return 0;
}