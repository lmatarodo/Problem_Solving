#include <iostream>
#include <queue>

using namespace std;

bool visit[100][100];
int board[100][100];
int dist[100][100]; // 각 노드로 가는 최단 경로 길이 저장
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int n, m;
    cin >> n >> m;
    queue<pair<int, int>> q;
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            board[i][j] = s[j] - '0';
        }
    }

    q.push({0,0});
    visit[0][0] = true; // 첫번째 노드 방문 처리
    dist[0][0] = 1; // 첫번째 노드는 방문하는 노드 수가 1개

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = curr.first + dx[dir];
            int ny = curr.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visit[nx][ny] || board[nx][ny] == 0) continue;

            q.push({nx, ny});
            visit[nx][ny] = true;
            dist[nx][ny] = dist[curr.first][curr.second] + 1;
        }
    }

    cout << dist[n -1 ][m - 1];

    return 0;
}