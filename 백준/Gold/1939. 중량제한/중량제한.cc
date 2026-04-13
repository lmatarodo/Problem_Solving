#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int n, m;
vector<pair<int, int>> adj[10002]; // 정점 번호, 비용
bool visited[10002];

bool bfs(int st, int en, int weight) { // 주어진 비용으로 시작점에서 끝점까지 갈 수 있는지를 확인
    fill(visited, visited + n + 1, false);
    queue<int> q; // 정점 번호
    q.push(st);
    visited[st] = true;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == en) return true;
        for (auto nxt: adj[cur]) {
            if (nxt.Y >= weight && visited[nxt.X] == false) {
                visited[nxt.X] = true;
                q.push(nxt.X);
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;

    int a, b, cost;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> cost;
        adj[a].push_back({b, cost});
        adj[b].push_back({a, cost});
    }

    int st, en;
    cin >> st >> en;

    int left = 1, right = 1e9;
    int ans = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (bfs(st, en, mid)) {
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << ans;
    
    return 0;
}