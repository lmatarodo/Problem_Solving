#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int n, m, k;
int board[102][102];
bool visited[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        int stx, sty, enx, eny;
        cin >> sty >> stx >> eny >> enx;
        for (int i = stx; i < enx; i++) {
            for (int j = sty; j < eny; j++) {
                board[i][j] = -1; // 갈 수 없는 곳으로 설정
            }
        }
    }

    int cnt = 0; // 영역 갯수
    vector<int> v; // 영역 별 넓이
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0 && !visited[i][j]) {
                cnt++;
                int area = 0; // 영역의 넓이
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty()) {
                    auto cur = q.front(); q.pop();
                    area++;
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (visited[nx][ny] || board[nx][ny] == -1) continue;
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
                v.push_back(area);
            }
        }
    }

    sort(v.begin(), v.end());
    cout << cnt << "\n";
    for (int i : v)
        cout << i << " ";
    

    return 0;
}