#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
    int to;
    int type;
};

int max_cnt = 0;
vector<Edge> adj[101];
int N, K_limit;

void dfs(int step, vector<bool>& infected, int count) {
    
    max_cnt = max(max_cnt, count);
    
    if (step == K_limit || count == N) return;
    
    for (int type = 1; type <= 3; type++) {
        
        queue<int> q;
        vector<bool> next_infected = infected;
        int next_count = count;
        
        for (int i = 1; i <= N; i++) {
            if (infected[i]) q.push(i);
        }
        
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            
            for (auto nxt: adj[cur]) {
                if (nxt.type == type && !next_infected[nxt.to]) {
                    next_infected[nxt.to] = true;
                    next_count++;
                    q.push(nxt.to);
                }
            }
        }
        
        dfs(step + 1, next_infected, next_count);
    }
}


int solution(int n, int infection, vector<vector<int>> edges, int k) {
    int answer = 0;
    N = n; K_limit = k;
    
    for (auto edge: edges) {
        adj[edge[0]].push_back({edge[1], edge[2]});
        adj[edge[1]].push_back({edge[0], edge[2]});
    }
    vector<bool> is_infected(n + 1, false);
    is_infected[infection] = true;
    dfs(0, is_infected, 1);
    answer = max_cnt;
    return answer;
    
}