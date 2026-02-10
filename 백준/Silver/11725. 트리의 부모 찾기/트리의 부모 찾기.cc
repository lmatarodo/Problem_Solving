#include <iostream>
#include <vector>

using namespace std;

int n;
int p[100002];
vector<int> adj[100002];

void dfs(int cur) {
    for (int nxt: adj[cur]) {
        if (nxt == p[cur]) continue;
        p[nxt] = cur;
        dfs(nxt);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    for (int i = 2; i <= n; i++) cout << p[i] << "\n";

    return 0;
}