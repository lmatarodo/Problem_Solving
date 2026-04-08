#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int n, m;
vector<pair<int, int>> adj[1002]; // 비용, 정점변호
const int INF = 0x7fffffff;
int dist[1002];

int main() {    
    fill(dist, dist + 1002, INF);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].push_back({cost, v});
    }

    int st, en;
    cin >> st >> en;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, st});
    dist[st] = 0;

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (dist[cur.Y] < cur.X) continue;
        for (auto nxt: adj[cur.Y]) {
            if (dist[nxt.Y] > dist[cur.Y] + nxt.X) {
                dist[nxt.Y] = dist[cur.Y] + nxt.X;
                pq.push({dist[nxt.Y], nxt.Y});
            }
        } 
    }

    cout << dist[en];

    return 0;
}