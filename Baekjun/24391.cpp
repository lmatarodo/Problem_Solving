#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> p(100002, -1);

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

void uni(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return;
    if (p[u] > p[v]) swap(u, v);
    if (p[u] == p[v]) p[u]--;
    p[v] = u;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        uni(u, v);
    }

    int ans = 0, prev, curr;
    for (int i = 0; i < n; i++) {
        cin >> curr;
        if (i == 0) {prev = curr; continue;}
        if (find(prev) != find(curr)) ans++;
        prev = curr;
    }
    cout << ans;

}