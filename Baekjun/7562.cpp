#include <iostream>
#include <queue>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int T, l;
int board[302][302];

int main() {
    queue<pair<int, int>> q;

    
    cin >> T;
    while (T--) {
        cin >> l;
        for (int i = 0; i < l; i++) 
            fill(board[i], board[i] + l, -1);

        int stX, stY; 
        cin >> stX >> stY;
        q.push({stX, stY});
        board[stX][stY] = 0;

        int enX, enY;
        cin >> enX >> enY;

        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            if (cur.X == enX && cur.Y == enY) {
                cout << board[enX][enY] << "\n";
                break; 
            }

            for (int dir = 0; dir < 8; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
                if (board[nx][ny] != -1) continue;

                board[nx][ny] = board[cur.X][cur.Y] + 1;
                q.push({nx, ny});
            }
        }

    }

    return 0;
}