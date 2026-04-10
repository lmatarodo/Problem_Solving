#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int n, m;
int map[8][8];
bool visited[8][8];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y, int map[8][8]) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (map[nx][ny] == 0 && !visited[nx][ny]) {
                map[nx][ny] = 2;
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}


int main() {
    cin >> n >> m;
    vector<pair<int, int>> empty; // 빈 칸인 인덱스 리스트를 담아놓는 벡터 배열
    vector<pair<int, int>> virus; // 바이러스의 위치 리스트를 담아놓는 벡터 배열
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) empty.push_back({i, j});
            if (map[i][j] == 2) virus.push_back({i, j});
        }
    }

    int len = empty.size();
    int answer = 0;
    // 브루트포스 방식으로 3개의 벽을 세워봄
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            for (int k = j + 1; k < len; k++) {
                int temp_ans = 0;
                int temp_map[8][8];
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < m; y++) 
                        temp_map[x][y] = map[x][y];
                }

                temp_map[empty[i].X][empty[i].Y] = 1; temp_map[empty[j].X][empty[j].Y] = 1; temp_map[empty[k].X][empty[k].Y] = 1;
                for (int i = 0; i < n; i++) 
                    fill(visited[i], visited[i] + m, false);
                
                for (auto v: virus) {
                    bfs(v.X, v.Y, temp_map);
                }
                
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < m; y++) {
                        if(temp_map[x][y] == 0) temp_ans++;
                    }
                }

                if (temp_ans > answer) answer = temp_ans;
            }
        }
    }

    cout << answer;


    return 0;
}