#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<int> adj[n + 1]; 
    int dist[n + 1];
    queue<int> q;
    
    fill(dist, dist + n + 1, -1);
    
    for (int i = 0; i < edge.size(); i++) {
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }
    
    q.push(1);
    dist[1] = 0;
    
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        
        for (int nxt: adj[cur]) {
            if (dist[nxt] != -1) continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
    
    int maxDist = -1;
    for (int i = 1; i <= n; i++) {
        maxDist = max(maxDist, dist[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        if (dist[i] == maxDist) 
            answer++;
    }
    
    return answer;
}