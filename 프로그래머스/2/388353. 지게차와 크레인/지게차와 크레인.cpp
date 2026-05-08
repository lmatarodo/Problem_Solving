#include <string>
#include <vector>
#include <queue>

#define X first
#define Y second

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int solution(vector<string> storage, vector<string> requests) {
    int n = storage.size();
    int m = storage[0].size();
    int answer = 0;
    
    vector<vector<char>> board(n + 2, vector<char>(m + 2, '.'));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i + 1][j + 1] = storage[i][j];
        }
    }
    
    for (string r: requests) {
        vector<pair<int, int>> target_tomove;
        
        if (r.size() == 1) {
            vector<vector<bool>> is_outer(n + 2, vector<bool>(m + 2, false));
            queue<pair<int, int>> q;
            q.push({0, 0});
            is_outer[0][0] = true;
            
            while (!q.empty()) {
                auto cur = q.front(); q.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = cur.X + dx[d]; int ny = cur.Y + dy[d];
                    if (nx >= 0 && nx < n + 2 && ny >= 0 && ny < m + 2 && !is_outer[nx][ny]) {
                        if (board[nx][ny] == '.') {
                            q.push({nx, ny});
                            is_outer[nx][ny] = true;
                        }
                    }
                }
            }
            
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (board[i][j] == r[0]) {
                        for (int d = 0; d < 4; d++) {
                            int ni = i + dx[d]; int nj = j + dy[d];
                            if (is_outer[ni][nj]) {
                                target_tomove.push_back({i, j});
                                break;
                            }
                        }
                    }
                }
            }
            
        }
            
        if (r.size() == 2) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (board[i][j] == r[0]) {
                        target_tomove.push_back({i, j});
                    }
                }
            }
        }
           
        for (auto p: target_tomove) {
            board[p.first][p.second] = '.';
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (board[i][j] != '.') answer++;
        }
    }
    
    return answer;
}