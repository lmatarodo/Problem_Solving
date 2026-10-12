#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define R first
#define C second

using namespace std;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

void normalize(vector<pair<int, int>>& shape) {
    sort(shape.begin(), shape.end());
    int minR = shape[0].R; int minC = shape[0].C;
    
    for (auto& i: shape) {
        i.R -= minR; i.C -= minC;
    }
}

vector<pair<int, int>> rotate(vector<pair<int, int>>& shape) {
    vector<pair<int, int>> unit;
    
    for (auto &s: shape) {
        unit.push_back({s.C, -s.R});
    }
    
    normalize(unit);
    return unit;
}

vector<pair<int, int>> bfs(int str, int stc, int type, vector<vector<bool>>& visited, vector<vector<int>>& map) {
    vector<pair<int, int>> unit;
    unit.push_back({str, stc});
    
    queue<pair<int, int>> q;
    q.push({str, stc});
    visited[str][stc] = true;
    
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nr = cur.R + dr[dir]; int nc = cur.C + dc[dir];
            if (nr < 0 || nr >= map.size() || nc < 0 || nc >= map.size()) continue;
            if (visited[nr][nc] || map[nr][nc] != type) continue;
            unit.push_back({nr, nc});
            q.push({nr, nc});
            visited[nr][nc] = true;
        }
    }
    normalize(unit);
    return unit;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    int n = game_board.size();
    
    vector<vector<pair<int, int>>> shapes;
    vector<vector<pair<int, int>>> empty;
    
    vector<vector<bool>> gvisited(n, vector<bool>(n, false));
    vector<vector<bool>> tvisited(n, vector<bool>(n, false));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (game_board[i][j] == 0 && !gvisited[i][j]) empty.push_back(bfs(i, j, 0, gvisited, game_board));
            if (table[i][j] == 1 && !tvisited[i][j]) shapes.push_back(bfs(i, j, 1, tvisited, table));
        }
    }
    
    vector<bool> used(shapes.size(), false);
    for (auto& e: empty) {
        for (int i = 0; i < shapes.size(); i++) {
            if (used[i]) continue;
            
            for (int dir = 0; dir < 4; dir++) {
                if (e == shapes[i]) {
                    answer += e.size();
                    used[i] = true;
                    break;
                }
                shapes[i] = rotate(shapes[i]);
            }
            if (used[i]) break;
        }
    }
    
    return answer;
}