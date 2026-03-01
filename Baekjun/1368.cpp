#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<int> p(10005, -1);
tuple<int, int, int> edge[100005]; // 비용, 정점1, 정점2

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (p[u] == p[v]) p[u]--;
    if (p[u] < p[v]) p[u] = v;
    else p[v] = u;
    return true;
}

int main() {

    int n; cin >> n;
    int e = 0;
    // 기싱의 정점에 우물을 파는 비용을 그 정점까지의 비용으로 두고 대응시킴
    for (int i = 1; i <= n; i++) {
        int cost; cin >> cost;
        edge[e++] = {cost, i, n + 1};
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <=n; j++) {
            int cost; cin >> cost;
            if (i >= j) continue; // !!중요: 중복 삽입 방지를 위해
            edge[e++] = {cost, i, j};
        }
    }
    n++; // 가상의 정점까지 포함시켜야 하므로 정점 수를 1 증가시킴
    sort(edge, edge + e);
    int cnt = 0; int ans = 0;
    for (int i = 0; i < e; i++) {
        int cost, a, b;
        tie(cost, a, b) = edge[i];
        if(!is_diff_group(a, b)) continue;
        ans += cost;
        cnt++;
        if (cnt == n - 1) break;
    }
    cout << ans;
}