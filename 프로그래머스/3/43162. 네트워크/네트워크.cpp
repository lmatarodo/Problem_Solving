#include <string>
#include <vector>

using namespace std;

void dfs(int node, vector<bool>& visited, vector<vector<int>>& computers) {
    
    for (int i = 0; i < computers[node].size(); i++) {
        if (i != node && !visited[i] && computers[node][i] == 1) {
            visited[i] = true;
            dfs(i, visited, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> visited(n, false);
    
    for (int i = 0; i < computers.size(); i++) {
        if (!visited[i]) {
            dfs(i, visited, computers);
            answer++;
        }
    }
    
    return answer;
}