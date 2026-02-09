#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m; 
vector<int> adj[1002];
bool vis[1002];

void dfs(int curr) {
    
    vis[curr] = true;
    for (auto nxt: adj[curr]) {
        if (vis[nxt]) continue;
        dfs(nxt);
    }
    
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int num = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            num++;
            dfs(i); // 연결된 정점이 하나라도 있고 아직 방문 x
        }
    }

    cout << num;
}