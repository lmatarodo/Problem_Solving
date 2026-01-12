#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

int visited[101][101];
int board[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    for (int i = 0; i < rectangle.size(); i++) {
        int x1 = rectangle[i][0] * 2;
        int y1 = rectangle[i][1] * 2;
        int x2 = rectangle[i][2] * 2;
        int y2 = rectangle[i][3] * 2;
        
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                if (i > x1 && i < x2 && j > y1 && j < y2) 
                    board[i][j] = -1;
                else if (board[i][j] != -1)
                    board[i][j] = 1; // 테두리 후보들을 채움
            }
        }
    }
    
    for (int i = 0; i < 102; i++) {
        for (int j = 0; j < 102; j++) {
            if (board[i][j] == -1) board[i][j] = 0;
        }
    }
    
    queue<pair<int, int>> q;
    q.push({characterX * 2, characterY * 2});
    visited[characterX * 2][characterY * 2]++;
    
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            bool isvalid = false;
            int nx = curr.first + dx[dir];
            int ny = curr.second + dy[dir];
            
            if (nx < 1 || nx > 100 || ny < 1 || ny > 100) continue; // 범위 벗어나면 스킵
            if (visited[nx][ny] > 0) continue; // 이미 방문한 적이 있으면 스킵
            if (board[nx][ny] != 1) continue;
            q.push({nx, ny});
            visited[nx][ny] = visited[curr.first][curr.second] + 1;
        }
        
    }
    
    answer = visited[itemX * 2][itemY * 2] / 2;
    return answer;
}