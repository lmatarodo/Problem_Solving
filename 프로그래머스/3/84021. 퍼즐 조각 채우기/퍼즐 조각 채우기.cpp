#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool s_visited[52][52];
bool b_visited[52][52];

vector<pair<int, int>> rotateShape(vector<pair<int, int>>& shape) {
    for (auto& coord: shape) {
        int x = coord.X;
        int y = coord.Y;
        coord.X = y;
        coord.Y = -x;
    }
    
    int minX = 100;
    int minY = 100;
    for (auto& coord: shape) {
        minX = min(minX, coord.X);
        minY = min(minY, coord.Y);
    }
    
    for (auto& coord: shape) {
        coord.X -= minX;
        coord.Y -= minY;
    }
    
    sort(shape.begin(), shape.end());
    return shape;
}


int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    
    vector<vector<pair<int, int>>> shapes; // 도형들 좌표 모음, 10개 선언해놓음 미리
    vector<vector<pair<int, int>>> blanks; // 빈칸들 좌표 모음
    queue<pair<int, int>> s_q;
    queue<pair<int, int>> b_q;
    int n = table.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (table[i][j] == 1 && !s_visited[i][j]) {
                vector<pair<int, int>> shape;
                s_q.push({i, j});
                s_visited[i][j] = true;
                shape.push_back({i, j});
                
                while (!s_q.empty()) {
                    auto cur = s_q.front(); s_q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (s_visited[nx][ny] || table[nx][ny] == 0) continue;
                        s_q.push({nx, ny});
                        s_visited[nx][ny] = true;
                        shape.push_back({nx, ny});
                    }
                }
                int minX = 100; int minY = 100;
                
                for (auto s: shape) {
                    minX = min(s.X, minX);
                    minY = min(s.Y, minY);
                }
                
                for (auto& s: shape) { // 꼭 참조로 받아야 원본이 수정됨!! 주의
                    s.X -= minX;
                    s.Y -= minY;
                }
                sort(shape.begin(), shape.end());
                shapes.push_back(shape);
            }
            
            if (game_board[i][j] == 0 && !b_visited[i][j]) {
                vector<pair<int, int>> blank;
                b_q.push({i, j});
                b_visited[i][j] = true;
                blank.push_back({i, j});
                
                while (!b_q.empty()) {
                    auto cur = b_q.front(); b_q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (b_visited[nx][ny] || game_board[nx][ny] == 1) continue;
                        b_q.push({nx, ny});
                        b_visited[nx][ny] = true;
                        blank.push_back({nx, ny});
                    }
                }
                
                int minX = 100; int minY = 100;
                for (auto b: blank) {
                    minX = min(b.X, minX);
                    minY = min(b.Y, minY);
                }
                
                for (auto& b: blank) { // 꼭 참조로 받아야 원본이 수정됨!! 주의
                    b.X -= minX;
                    b.Y -= minY;
                }
                
                sort(blank.begin(), blank.end());
                blanks.push_back(blank);
            }
        }
    }
    
    
    vector<bool> isused(shapes.size(), false);
    for (auto& blank: blanks) {
        for (int i = 0; i < shapes.size(); i++) {
            if (isused[i]) continue;
            if (blank.size() != shapes[i].size()) continue;
            
            
            vector<pair<int, int>> rotated = shapes[i];
            bool isMatch = false;
            for (int r = 0; r < 4; r++) {
                if (rotated == blank) {
                    isMatch = true;
                    break;
                }
                rotated = rotateShape(rotated);
            }
            
            if (isMatch) {
                isused[i] = true;
                answer += blank.size();
                break;
            }
        }
    }    
    
    return answer;
}