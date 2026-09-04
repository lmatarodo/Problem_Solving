#include <string>
#include <vector>
#include <queue>

#define X first
#define Y second

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int stx, int sty, vector<string> place, vector<vector<int>>& dist) {
    queue<pair<int, int>> q;
    q.push({stx, sty});
    dist[stx][sty] = 0;
    
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
            
        for (int d = 0; d < 4; d++) {
            int nx = cur.X + dx[d];
            int ny = cur.Y + dy[d];
            
            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if (dist[nx][ny] != -1 || place[nx][ny] == 'X') continue;
            
            q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            
            if (place[nx][ny] == 'P') {
                return dist[nx][ny];
            }
        }
    }
    return -1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (auto place: places) {
        
        bool isOk = true;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (place[i][j] == 'P') {
                    vector<vector<int>> dist(5, vector<int>(5, -1));
                    int minDist = bfs(i, j, place, dist);
                    if (minDist != -1 && minDist <= 2) {
                        isOk = false;
                        break;
                    }
                }
            }
            if (!isOk) break;
        }
        if (isOk) answer.push_back(1);
        else answer.push_back(0);
    }
    
    return answer;
}