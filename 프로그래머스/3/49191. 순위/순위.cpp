#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

void dfs(int idx, vector<bool>& visited, vector<vector<int>>& adj) {
    for (int nxt: adj[idx]) {
        if (!visited[nxt]) {
            visited[nxt] = true;
            dfs(nxt, visited, adj);
        }
    }
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<int>> adj1(n + 1);
    vector<vector<int>> adj2(n + 1);
    vector<unordered_set<int>> canGo(n + 1);
    
    for (int i = 0; i < results.size(); i++) {
        adj1[results[i][0]].push_back(results[i][1]);
        adj2[results[i][1]].push_back(results[i][0]);
    }
    
    for (int i = 1; i <= n; i++) {
        vector<bool> visited(n + 1, false);
        dfs(i, visited, adj1);
        
        for (int j = 1; j <= n ;j++) {
            if (visited[j]) canGo[i].insert(j);
        }
        fill(visited.begin(), visited.end(), false);
        dfs(i, visited, adj2);
        
        for (int j = 1; j <= n ;j++) {
            if (visited[j]) canGo[i].insert(j);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (canGo[i].size() == n - 1) answer++;
    }
    
    return answer;
}