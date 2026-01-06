#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int box[102][102][102];
int dist[102][102][102];

int dx[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};

int main() {
    int n, m, h; // h가 높이, m이 가로길이, n이 세로길이
    cin >> m >> n >> h;
    queue<tuple<int, int, int>> q;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> box[i][j][k];
                if (box[i][j][k] == 1) 
                    q.push({i, j, k}); // 각 시작점들을 모두 큐에 넣음            
                else if (box[i][j][k] == 0)
                    dist[i][j][k] = -1; // 익지 않은 토마토 칸들은 모두 거리 -1로 초기화    
                }
        }   
    }

    while (!q.empty()) {
        tuple<int, int, int> curr = q.front();
        q.pop();

        for (int dir = 0; dir < 6; dir++) {
            int nx = get<0>(curr) + dx[dir];
            int ny = get<1>(curr) + dy[dir];
            int nz = get<2>(curr) + dz[dir];

            if (nx < 0 || nx >= h || ny < 0 || ny >= n || nz < 0 || nz >= m) continue;
            if (box[nx][ny][nz] != 0 || dist[nx][ny][nz] != -1) continue;

            dist[nx][ny][nz] = dist[get<0>(curr)][get<1>(curr)][get<2>(curr)] + 1;
            box[nx][ny][nz] = 1;
            q.push({nx, ny, nz});
        }
    }

    int count = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (dist[i][j][k] == -1) {
                    cout << "-1";
                    return 0;
                }
                if (count <= dist[i][j][k]) count = dist[i][j][k];
                }
        }
    }

    cout << count;

    return 0;
}