#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p(10005, -1);

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

// 두 정점이 같은 그룹인지 확인하고 다른 그룹이라면 같은 그룹으로 만들어줌
bool is_diff_group(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return false;
    if (p[u] == p[v]) p[u]--;
    if (p[u] > p[v]) p[v] = u;
    else p[u] = v;
    return true;
}

int v, e;
tuple<int, int, int> edge[100005];

int main() {
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = {cost, a, b};
    }

    sort(edge, edge + e);
    int cnt = 0; int ans = 0;
    for (int i = 0; i < e; i++) {
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if (!is_diff_group(a, b)) continue;
        ans += cost;
        cnt++;
        if (cnt == v - 1) break;
    }

    cout << ans;

    return 0;
}