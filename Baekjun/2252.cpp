#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int deg[32002];
vector<int> adj[32002];
vector<int> answer;
queue<int> q;

int main() {

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        answer.push_back(cur);

        for (int nxt : adj[cur]) {
            deg[nxt]--;
            if (deg[nxt] == 0) q.push(nxt);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << answer[i] << ' ';
    }

    return 0;
}