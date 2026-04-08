#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(vector<string>& board) {
    queue<pair<int, int>> q;
    int n = board.size();
    int m = board[0].size();
    int dist[n][m];
    for (int i = 0; i < n; i++) {
        fill(dist[i], dist[i] + m, -1);
    }
    
    bool found = false;
    // 시작점 삽입
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'R'){
                q.push({i, j});
                dist[i][j] = 0;
                found = true;
                break;
            }
        }
        if (found) break;
    }
    
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) { // 4방향에 대해 탐색
            int nx = cur.X; int ny = cur.Y;
            while (true) {
                nx = nx + dx[dir];
                ny = ny + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 'D') {
                    nx -= dx[dir]; ny -= dy[dir];
                    break; // 원복 후 while문 빠져나옴
                }
            }
            if (dist[nx][ny] != -1) continue; // 이미 방문했었던 지점이면 건너뜀
            q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            
            if (board[nx][ny] == 'G') return dist[nx][ny];
        }
        
    }
    
    return -1;
}

int solution(vector<string> board) {
    int answer = 0;
    answer = bfs(board);
    
    return answer;
}