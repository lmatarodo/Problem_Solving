#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, n, m, k;
vector<int> adj[1000001];
int group_id[1000001];

// g_num: 현재 탐색 중인 그룹의 고유 번호
void bfs(int st, int g_num) {
    queue<int> q;
    q.push(st);
    group_id[st] = g_num;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto nxt : adj[cur]) {
            if (group_id[nxt] == -1) { // 방문하지 않은 노드라면
                group_id[nxt] = g_num; // 같은 그룹 번호를 부여
                q.push(nxt);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); // 속도 향상

    cin >> T;
    for (int idx = 1; idx <= T; idx++) {
        cin >> n >> k;

        // 1. 초기화 (이전 케이스 데이터 삭제)
        for (int i = 0; i <= n; i++) {
            adj[i].clear();
            group_id[i] = -1;
        }

        for (int j = 0; j < k; j++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // 2. 모든 노드를 돌며 BFS 수행 (연결 요소 찾기)
        int g_cnt = 0;
        for (int j = 0; j < n; j++) { // 노드 번호 범위(0~n-1 또는 1~n) 확인 필요
            if (group_id[j] == -1) {
                bfs(j, g_cnt++);
            }
        }

        cin >> m;
        cout << "Scenario " << idx << ":" << '\n';
        for (int j = 0; j < m; j++) {
            int u, v;
            cin >> u >> v;
            // 같은 그룹 번호를 가졌다면 연결된 것!
            if (group_id[u] == group_id[v]) cout << "1" << '\n';
            else cout << "0" << '\n';
        }
        if (idx != T) cout << '\n'; // 케이스 사이 빈 줄 (필요시)
    }
    return 0;
}