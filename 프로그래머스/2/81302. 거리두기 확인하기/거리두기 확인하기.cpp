#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define X first
#define Y second

using namespace std;

int dist[6][6];
char room[6][6];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool bfs(int x, int y) {
    for (int i = 0; i < 5; i++)
        fill(dist[i], dist[i] + 5, -1);
    
    queue<pair<int, int>> q;
    q.push({x, y});
    dist[x][y] = 0;
    
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if (dist[nx][ny] == -1 && room[nx][ny] != 'X') {
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                q.push({nx, ny});
                if (room[nx][ny] == 'P' && dist[nx][ny] <= 2) return false;
            }
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (auto place: places) {
        vector<pair<int, int>> p_pos; // p인 인덱스 들의 위치 저장해놓음
        // 초기화 페이스
        for (int i = 0; i < place.size(); i++) {
            for (int j = 0; j < place[0].size(); j++) {
                room[i][j] = place[i][j];
                if (place[i][j] == 'P') p_pos.push_back({i, j});
                dist[i][j] = -1;
            }
        }
        
        bool isViolate = false;
        for (auto p: p_pos) {
            if (!bfs(p.first, p.second)) isViolate = true;
        }
        if (isViolate) answer.push_back(0);
        else answer.push_back(1);
    }
    
    
    return answer;
}