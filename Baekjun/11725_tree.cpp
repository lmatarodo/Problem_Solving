#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n;
int p[100002];
vector<int> adj[100002];

void bfs() {
    queue<int> q;
    q.push(1);
    
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt: adj[cur]) {
            if (nxt == p[cur]) continue;
            p[nxt] = cur;
            q.push(nxt);
        }
    }
}

void dfs() {
    stack<int> st;
    st.push(1);

    while (!st.empty()) {
        int cur = st.top(); st.pop();
        for (int nxt: adj[cur]) {
            if(p[cur] == nxt) continue;
            p[nxt] = cur;
            st.push(nxt);
        }
    }
}   

void dfs2(int cur) {
    for (int nxt: adj[cur]) {
        if (nxt == p[cur]) continue;
        p[nxt] = cur;
        dfs2(nxt);
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

    //bfs();
    dfs();
    //dfs2(1);
    
    for (int i = 2; i <= n; i++) cout << p[i] << "\n";

    return 0;
}