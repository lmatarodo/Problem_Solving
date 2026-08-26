#include <vector>
#include <queue>

#define X first
#define Y second

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int solution(vector<vector<int>> maps)
{
    int answer = 0;
    int n = maps.size(); int m = maps[0].size();
    vector<vector<int>> dist(n, vector<int>(m, -1));
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 0;
    
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        
        for (int d = 0; d < 4; d++) {
            int nx = cur.X + dx[d];
            int ny = cur.Y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] > -1 || maps[nx][ny] == 0) continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        }
    }
    
    if (dist[n - 1][m - 1] == -1) answer = -1; 
    else answer = dist[n - 1][m - 1] + 1;
    return answer;
}