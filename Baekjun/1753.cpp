#include <iostream>
#include <queue>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int st, v, e;
const int INF = 0x7fffffff;
int dist[20005]; // 최단 거리
vector<pair<int ,int>> adj[20005]; // 비용, 정점 번호

int main() {

    cin >> v >> e;
    cin >> st;
    fill(dist, dist + 20005, INF);

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v}); 
    }
    // 비용, 정점 번호
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[st] = 0;
    pq.push({0, st});

    // 다익스트라 알고리즘
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (dist[cur.Y] != cur.X) continue;
        for (auto nxt: adj[cur.Y]) {
            if (dist[nxt.Y] > dist[cur.Y] + nxt.X) { 
                dist[nxt.Y] = dist[cur.Y] + nxt.X;
                pq.push({dist[nxt.Y], nxt.Y});
            } 
        }
    }

    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }

}