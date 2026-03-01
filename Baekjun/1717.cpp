#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> p(1000001, -1);

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return false;
    if (p[v] < p[u]) swap(u, v);
    if (p[u] == p[v]) p[u]--;
    p[v] = u;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 0) {
            uni(u, v);
        }
        else if (op == 1) {
            u = find(u); v = find(v);
            if (u == v) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}