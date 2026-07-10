#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));
    
    for (auto r: results) {
        graph[r[0]][r[1]] = true;
    }
    
    for (int k = 1; k <= n; k++) {
        for (int s = 1; s <= n; s++) {
            for (int t = 1; t <= n; t++) {
                if (graph[s][k] && graph[k][t]) graph[s][t] = true;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            //if (i == j) continue;
            if (graph[i][j] || graph[j][i]) cnt++;
        }
        if (cnt == n - 1) answer++;
    }
    
    return answer;
}