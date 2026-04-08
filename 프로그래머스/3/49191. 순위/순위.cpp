#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> winadj(102);
vector<vector<int>> loseadj(102); // 각각 win / lose 그래프
bool visited[102];

int bfs(int st, vector<vector<int>>& graph) {
    queue<int> q;
    fill(visited, visited + 102, false);
    
    q.push(st);
    visited[st] = true;
    int cnt = 0;    
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        
        for (int nxt: graph[cur]) {
            if(visited[nxt]) continue;
            visited[nxt] = true;
            q.push(nxt);
            cnt++;
        }
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for (auto& result: results) {
        winadj[result[0]].push_back(result[1]);
        loseadj[result[1]].push_back(result[0]);
    }
    
    for (int i = 1; i <= n; i++) {
        int wincnt = bfs(i, winadj);
        int losecnt = bfs(i, loseadj);
        
        if (wincnt + losecnt == n - 1)
            answer++;
        
    }
    
    return answer;
}