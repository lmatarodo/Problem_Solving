#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int dist[102];
vector<pair<int, int>> ladder;
vector<pair<int, int>> snake;

void bfs(int st) {
    queue<int> q;
    q.push(st);
    dist[st] = 0;

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int i = 1; i <= 6; i++) {
            int nxt = cur + i;
            if (nxt > 100) continue;

            // 주사위를 던진 다음 위치가 뱀 또는 사다리의 위치해 있으면 바로 그 다음 위치를 수정함!!
            // 사다리와 뱀 이동을 별도의 턴으로 보지 않는다!!
            for (auto l: ladder) {
                if (l.first == nxt) {
                    nxt = l.second;
                    break;
                }
            }

            for (auto s: snake) {
                if (s.first == nxt) {
                    nxt = s.second;
                    break;
                }
            }

            if (dist[nxt] == -1) {
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        ladder.push_back({x, y});
    }

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        snake.push_back({x, y});
    }

    fill(dist, dist + 102, -1);

    bfs(1);
    cout << dist[100];

    return 0;
}