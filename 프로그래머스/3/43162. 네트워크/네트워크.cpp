#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

bool visited[201];

void bfs(int node, vector<vector<int>>& computers) {
    queue<int> q;
    q.push(node);
    visited[node] = true;
    
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        
        for (int i = 0; i < computers[cur].size(); i++) {
            if (computers[cur][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i = 0; i < computers.size(); i++) {
        if (!visited[i]) {
            answer++;
            cout << i << "\n";
            bfs(i, computers);
        }
    }
    
    return answer;
}