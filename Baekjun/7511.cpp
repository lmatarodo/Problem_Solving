#include <iostream>
#include <vector>

using namespace std;

int T, n, k, m;
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
    cin >> T;
    for (int idx = 1; idx <= T; idx++) {
        fill(p.begin(), p.begin() + n + 1, -1);
        cin >> n;
        cin >> k;

        for (int i = 0; i < k; i++) {
            int u, v;
            cin >> u >> v;
            uni(u, v);
        }

        cin >> m;
        vector<int> ans;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u = find(u);
            v = find(v);

            if (u == v) ans.push_back(1);
            else ans.push_back(0);
        }

        cout << "Scenario " << idx << ":\n";
        for (int i = 0;i < m; i++) {
            cout << ans[i] << '\n';
        }
        if (idx != T) cout << '\n';
    }

    return 0;
}