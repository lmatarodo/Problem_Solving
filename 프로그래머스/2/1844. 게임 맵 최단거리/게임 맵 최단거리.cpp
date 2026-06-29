#include <vector>
#include <queue>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int dist[101][101];

int bfs(vector<vector<int>>& maps) {
    int n = maps.size();
    int m = maps[0].size();
    
    for (int i = 0; i < n; i++)
        fill(dist[i], dist[i] + m, -1);
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 0;
    
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (maps[nx][ny] == 0 || dist[nx][ny] != -1) continue;
            
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }
    
    if (dist[n - 1][m - 1] == -1) return -1;
    return dist[n - 1][m - 1] + 1;
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    answer = bfs(maps);
    return answer;
}