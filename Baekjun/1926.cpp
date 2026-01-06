#include <iostream>
#include <queue>

using namespace std;

int board[500][500];
bool visit[500][500];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int n, m;
    int count = 0, area = 0; // 그림의 개수, 가장 넓은 그림의 넓이
    cin >> n >> m;
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0 ;j < m; j++) {
            if (board[i][j] == 1 && !visit[i][j]) { // 아직 방문하지 않은 영역
                int tempArea = 1;
                count++; // 영역의 갯수 확장
                q.push({i, j});
                visit[i][j] = true; // 해당 노드를 큐에 넣고 방문 표시

                while (!q.empty()) { // 해당 노드에서 BFS 실시
                    pair<int ,int> curr = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = curr.first + dx[dir];
                        int ny = curr.second + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (visit[nx][ny] || board[nx][ny] == 0) continue;

                        tempArea++;
                        q.push({nx, ny});
                        visit[nx][ny] = true;
                    }
                }
                if (tempArea > area) area = tempArea; // 영역 최댓값 갱신
            }
        }
    }   

    cout << count << "\n" << area;

    return 0;
}