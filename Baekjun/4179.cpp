#include <iostream>
#include <queue>

using namespace std;

char board[1002][1002];
int dist1[1002][1002]; // 불에 관한 거리 맵
int dist2[1002][1002]; // 지훈이에 관한 거리 맵

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int r, c;
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++) {
            board[i][j] = s[j];
            dist1[i][j] = -1;
            dist2[i][j] = -1;
        }
    }

    queue<pair<int, int>> q1; // 불에 관한 큐
    queue<pair<int, int>> q2; // 지훈이에 관한 큐

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == 'F'){
                q1.push({i, j});
                dist1[i][j] = 0; // 불인 노드를 만나면 큐에 넣고 방문처리
            }
            else if (board[i][j] == 'J'){
                q2.push({i, j});
                dist2[i][j] = 0; // 지훈인 노드를 만나면 큐에 넣고 방문처리
            }

        }
    }

    // 불에 관한 BFS
    while (!q1.empty()) {
        auto curr = q1.front();
        q1.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = curr.first + dx[dir];
            int ny = curr.second + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (board[nx][ny] == '#' || dist1[nx][ny] >= 0) continue;

            q1.push({nx, ny});
            dist1[nx][ny] = dist1[curr.first][curr.second] + 1;
        }
    }

    // 지훈에 관한 BFS
    while (!q2.empty()) {
        auto curr = q2.front();
        q2.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = curr.first + dx[dir];
            int ny = curr.second + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) { // (핵심 1) 범위를 벗어났다는 것은 탈출에 성공했음을 의미
                cout << dist2[curr.first][curr.second] + 1;
                return 0;
            }

            if (board[nx][ny] == '#' || dist2[nx][ny] >= 0) continue;
            if (dist1[nx][ny] != -1 && dist2[curr.first][curr.second] + 1 >= dist1[nx][ny]) continue;
            // (핵심 2) 해당 노드에 불이 방문했었는지 여부도 꼭 확인을 해주어야 함

            q2.push({nx, ny});
            dist2[nx][ny] = dist2[curr.first][curr.second] + 1;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}