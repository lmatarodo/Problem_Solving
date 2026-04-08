#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool visited[102];

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    
    for (int i = 0; i < wires.size(); i++) { // i번째 경로만 제외시키고
        vector<vector<int>> adj(n + 1);
        fill(visited, visited + n + 1, false);
        queue<int> q1;
        queue<int> q2;
        for (int j = 0; j < wires.size(); j++) { // 하나하니씩 끊어본다.
            if (j == i) continue;
            adj[wires[j][0]].push_back(wires[j][1]);
            adj[wires[j][1]].push_back(wires[j][0]);
        }
        
        q1.push(wires[i][0]); // 끊어진 두 점을 큐에 넣고 bfs 시작할것
        visited[wires[i][0]] = true;
        int fcnt = 1; // 첫번째 부분에서 얼마나 노드가 있는지,
        while (!q1.empty()) {
            int cur = q1.front(); q1.pop();
            fcnt++;
            for (int nxt: adj[cur]) {
                if (!visited[nxt]){
                    visited[nxt] = true;
                    q1.push(nxt);
                }
            }
        }
        q2.push(wires[i][1]);
        visited[wires[i][1]] = true;
        int scnt = 1; // 첫번째 부분에서 얼마나 노드가 있는지,
        while (!q2.empty()) {
            int cur = q2.front(); q2.pop();
            scnt++;
            for (int nxt: adj[cur]) {
                if (!visited[nxt]){
                    visited[nxt] = true;
                    q2.push(nxt);
                }
            }
        }
        
        answer = min(answer, abs(fcnt - scnt));
        
    }
    
    
    return answer;
}