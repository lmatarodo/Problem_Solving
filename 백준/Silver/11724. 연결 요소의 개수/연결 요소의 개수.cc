#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m; 
vector<int> adj[1002];
bool vis[1002];

int bfs() {
    int num = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        num++;
        queue<int> q;
        q.push(i);
        vis[i] = true;
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            for (auto nxt: adj[curr]) {
                if (vis[nxt]) continue;
                q.push(nxt);
                vis[nxt] = true;
            }
        }
    }
    return num;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << bfs();

}