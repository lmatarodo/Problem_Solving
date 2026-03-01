#include <iostream>
#include <vector>
#include <queue>

#define X first
#define Y second

using namespace std;

int st, en, v, e;
const int INF = 0x7fffffff;
int dist[1002];
int pre[1002]; // 이전에 거쳐온 도시 번호
vector<pair<int, int>> adj[1002]; // 비용, 정점 번호

int main() {
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        adj[a].push_back({cost, b});
    }

    cin >> st >> en;
    fill(dist, dist + 1002, INF);
    // 비용, 정점 번호
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[st] = 0;
    pq.push({0, st});

    // 다익스트라
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (dist[cur.Y] != cur.X) continue;
        for (auto nxt: adj[cur.Y]) {
            if (dist[nxt.Y] > dist[cur.Y] + nxt.X) {
                pre[nxt.Y] = cur.Y; // 이전에 거쳐온 도시 번호 갱신
                dist[nxt.Y] = dist[cur.Y] + nxt.X;
                pq.push({dist[nxt.Y], nxt.Y});
            }
        }
    }

    vector<int> path;
    int cur = en; path.push_back(en);
    while (cur != st) {
        cur = pre[cur];
        path.push_back(cur);
    }

    cout << dist[en] << '\n';
    cout << path.size() << '\n';
    for (auto it = path.rbegin(); it != path.rend(); it++) 
        cout << *it << ' ';
}