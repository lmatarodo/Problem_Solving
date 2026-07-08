#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<pair<int, int>> normalize(vector<pair<int, int>>& shape) {
    int minX = 1e9; int minY = 1e9;
    for (auto s: shape) {
        if (s.X < minX) minX = s.X;
        if (s.Y < minY) minY = s.Y;
    }
    
    for (auto& s: shape) {
        s.X -= minX;
        s.Y -= minY;
    }
    
    sort(shape.begin(), shape.end());
    return shape;
}

void rotate(vector<pair<int, int>>& shape) {
    for (auto& s: shape) {
        int curX = s.X;
        s.X = s.Y;
        s.Y = -curX;
    }
    
    normalize(shape);
}

vector<pair<int, int>> bfs(int sX, int sY, vector<vector<int>>& board, vector<vector<bool>>& visited, int target) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> shape;
    int n = board.size();

    q.push({sX, sY}); shape.push_back({sX, sY});
    visited[sX][sY] = true;
    
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (visited[nx][ny] || board[nx][ny] != target) continue;
            q.push({nx, ny});
            shape.push_back({nx, ny});
            visited[nx][ny] = true;
        }
    }
    
    return normalize(shape);
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    int n = game_board.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    
    vector<vector<pair<int, int>>> empty;
    vector<vector<pair<int, int>>> shapes;
    
    for (int i = 0; i < game_board.size(); i++) {
        for (int j = 0; j < game_board[i].size(); j++) {
            if (game_board[i][j] == 0 && visited[i][j] == false) {
                empty.push_back(bfs(i, j, game_board, visited, 0));
            }
        }
    }
    
    for (int i = 0; i < n; i++)
        fill(visited[i].begin(), visited[i].end(), false);
    
    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table[i].size(); j++) {
            if (table[i][j] == 1 && visited[i][j] == false) {
                shapes.push_back(bfs(i, j, table, visited, 1));
            }
        }
    }
    
    vector<bool> used(shapes.size(), false);
    
    for (auto e: empty) {
        for (int s = 0; s < shapes.size(); s++) {
            if (used[s]) continue;
            if (e.size() != shapes[s].size()) continue;
            
            
            for (int d = 0; d < 4; d++) {
                if (e == shapes[s]) {
                    used[s] = true;
                    answer += shapes[s].size();
                    break;
                }
                rotate(shapes[s]);
            }
            
            if (used[s]) break;
        }
    }
    
    return answer;
}