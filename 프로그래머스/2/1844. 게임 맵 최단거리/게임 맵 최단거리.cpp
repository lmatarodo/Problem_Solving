#include<vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<int>> visit(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    q.push({0, 0});
    visit[0][0] = 0;
    
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = curr.first + dx[dir];
            int ny = curr.second + dy[dir];  
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) 
                continue;
            if (visit[nx][ny] >= 0 || maps[nx][ny] == 0) continue;
            
            visit[nx][ny] = visit[curr.first][curr.second] + 1;
            q.push({nx, ny});
        }
    }
    
    if (visit[n - 1][m - 1] == -1) answer = -1;
    else answer = visit[n - 1][m - 1] + 1;
    
    
    return answer;
}