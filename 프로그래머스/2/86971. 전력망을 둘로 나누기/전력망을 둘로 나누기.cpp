#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool visited[102];

int dfs(int cur, vector<vector<int>>& adj) {
    visited[cur] = true;
    int count = 1;
    for (int nxt: adj[cur]) {
        if (!visited[nxt]) {
            count += dfs(nxt, adj);
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    
    int min_diff = 200;
    for (int i = 0; i < wires.size(); i++) {
        vector<vector<int>> adj(n + 1);
        fill(visited, visited + n + 1, false);
        
        for (int j = 0; j < wires.size(); j++) {
            if (i == j) continue;
            adj[wires[j][0]].push_back(wires[j][1]);
            adj[wires[j][1]].push_back(wires[j][0]);
        }
        
        int cnt1 = dfs(wires[i][0], adj);
        int cnt2 = dfs(wires[i][1], adj);
        int cur_diff = abs(cnt1 - cnt2);
        if (min_diff > cur_diff) min_diff = cur_diff;
    }
    answer = min_diff;
    
    return answer;
}