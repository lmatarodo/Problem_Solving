#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int board[101][101];
int dist[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int stX, int stY, int enX, int enY) {
    for (int i = 0; i < 101; i++) 
        fill(dist[i], dist[i] + 101, -1);
    
    queue<pair<int, int>> q;
    q.push({stX, stY});
    dist[stX][stY] = 0;
    
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        
        for (int d = 0; d < 4; d++) {
            int nx = cur.first + dx[d];
            int ny = cur.second + dy[d];
            if (nx < 1 || nx >= 101 || ny < 1 || ny >= 101) continue;
            if (board[nx][ny] != 1 || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
    
    return dist[enX][enY] / 2;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    for (auto rect: rectangle) {
        int x1 = rect[0] * 2;
        int y1 = rect[1] * 2;
        int x2 = rect[2] * 2;
        int y2 = rect[3] * 2;
        
        for (int x = x1; x <= x2; x++) {
            for (int y = y1; y <= y2; y++) {
                if (x > x1 && x < x2 && y > y1 && y < y2) {
                    board[x][y] = 2;
                }
                
                else {
                    if (board[x][y] != 2) {
                        board[x][y] = 1;
                    }
                }
            }
        }
    }
    
    answer = bfs(characterX * 2, characterY * 2, itemX * 2, itemY * 2);
    
    return answer;
}