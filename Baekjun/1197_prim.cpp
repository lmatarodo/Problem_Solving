#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define X first
#define Y second

vector<pair<int, int>> adj[10005]; // 비용, 정점
priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq;
bool chk[10005];

int main() {

    int v, e; cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int cost, a, b;
        cin >> a >> b >> cost;
        adj[a].push_back({cost, b});
        adj[b].push_back({cost, a});
    }

    int cnt = 0;
    chk[1] = 1;
    for (auto nxt: adj[1])
        pq.push({nxt.X, 1, nxt.Y});
    
    int ans = 0;
    while (cnt < v - 1) {
        int cost, a, b;
        tie(cost, a, b) = pq.top(); pq.pop();
        if (chk[b]) continue;

        chk[b] = 1;
        ans += cost;
        cnt++;
        for (auto nxt: adj[b]) {
            if (!chk[nxt.Y])
                pq.push({nxt.X, b, nxt.Y});
        }
    }
    cout << ans;

    return 0;
}