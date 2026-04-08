#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v;
bool visited[100002];
vector<pair<int,int>> adj[100002]; // 정점 번호, 비용
int maxDist = 0;
int farNode = 0;

void dfs(int cur, int dist) {
    visited[cur] = true;
    if (dist > maxDist) {
        maxDist = dist;
        farNode = cur;
    }

    for (auto nxt: adj[cur]) {
        if (visited[nxt.first]) continue;
        dfs(nxt.first, dist + nxt.second);
    }
}

int main() {

    int node;
    int nxt; int price;
    cin >> v;
    for (int i = 1; i <= v; i++) {
        cin >> node;
        while (true) {
            cin >> nxt;
            if (nxt == -1) break;
            cin >> price;
            adj[node].push_back({nxt, price});
        }
    }

    dfs(1, 0);
    fill(visited, visited + 100002, false);
    
    maxDist = 0;
    dfs(farNode, 0);
    cout << maxDist;


    return 0;
}