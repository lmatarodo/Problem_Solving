#include <string>
#include <vector>
#include <queue>

#define R first
#define C second

using namespace std;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

int bfs(int stR, int stC, vector<vector<int>>& dist, vector<string>& place) { // 어느 한 P로부터 다른 P로 갈 수 있는 최단 거리 반환
    queue<pair<int, int>> q;
    q.push({stR, stC});
    dist[stR][stC] = 0;
    
    while (!q.empty()) {
        
        auto cur = q.front(); q.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            
            int nr = cur.R + dr[dir]; int nc = cur.C + dc[dir];
            if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue;
            if (dist[nr][nc] != -1 || place[nr][nc] == 'X') continue;
            
            q.push({nr, nc});
            dist[nr][nc] = dist[cur.R][cur.C] + 1;
            if (place[nr][nc] == 'P') return dist[nr][nc];
        }
    }
    
    return -1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (auto& place: places) {
        bool isOk = true;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (place[i][j] == 'P') {
                    vector<vector<int>> dist(5, vector<int>(5, -1));
                    int minDist = bfs(i, j, dist, place);
                    if (minDist != -1 && minDist <= 2) {
                        answer.push_back(0);
                        isOk = false;
                        break;
                    }
                }
            }
            if (!isOk) break;
        }
        if (isOk) answer.push_back(1);
    }
    
    return answer;
}