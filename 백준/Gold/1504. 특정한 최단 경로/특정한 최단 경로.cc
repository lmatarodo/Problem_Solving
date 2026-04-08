#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int n, e;
const int INF = 0x7fffffff;
vector<pair<int,int>> adj[802]; // 비용, 정점 번호
int dist[802];
int distv1[802];
int distv2[802];

void dijstra(int st, int* dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, st});
    dist[st] = 0;

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

}

int main() {
    fill(dist, dist + 802, INF);
    fill(distv1, distv1 + 802, INF);
    fill(distv2, distv2 + 802, INF);

    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    int v1, v2; cin >> v1 >> v2;

    dijstra(1, dist);
    dijstra(v1, distv1);
    dijstra(v2, distv2);

    long long path1 = dist[v1] + distv1[v2] + distv2[n];
    long long path2 = dist[v2] + distv2[v1] + distv1[n];

    if (dist[v1] == INF || distv1[v2] == INF || distv2[n] == INF) path1 = INF;
    if (dist[v2] == INF || distv2[v1] == INF || distv1[n] == INF) path2 = INF;

    long long ans = INF;
    ans = min(path1, path2);

    if (ans == INF) cout << -1;
    else cout << ans;
    return 0;
}