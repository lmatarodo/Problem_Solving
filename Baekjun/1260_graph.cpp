#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, v;
vector<int> adj[1002];
bool vis[1002];

void dfs(int start) {
    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int curr = st.top(); st.pop();
        if (vis[curr]) continue;
        vis[curr] = true; // 스택에서 값을 뽑은 후 방문 표시를 해줌
        cout << curr << " ";
        for (int i = 0; i < adj[curr].size(); i++) {
            int nxt = adj[curr][adj[curr].size() - i - 1];
            if (vis[nxt]) continue;
            st.push(nxt); // 스택의 특성 상 정렬을 역순으로 넣어야함
        }
    }
}

void dfs2(int curr) {
    vis[curr] = true;
    cout << curr << " ";
    for (auto nxt: adj[curr]) {
        if (!vis[nxt]){
            dfs2(nxt);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    vis[start] = true;

    while (!q.empty()) {
        int curr = q.front(); q.pop();
        cout << curr << " ";
        for (auto nxt: adj[curr]) {
            if (vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    }
}

int main() {

    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(v);
    //dfs2(v);
    cout << "\n";
    fill(vis, vis + 1002, false);
    bfs(v);
}