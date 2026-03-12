#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    const int INF = 10000;
    vector<int> adj[n + 1];
    int dist[n + 1][n + 1]; // A에서 B로 가는 최단 경로 저장
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++){
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    
    for (auto result: results) {
        adj[result[0]].push_back(result[1]);
        dist[result[0]][result[1]] = 1;
    }
    
    for (int i = 1; i <= n; i++) { // 경유지
        for (int s = 1; s <= n; s++) { // 출발지
            for (int t = 1; t <= n; t++) { // 도착지
                if (dist[s][t] > dist[s][i] + dist[i][t]) {
                    dist[s][t] = dist[s][i] + dist[i][t];
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (dist[i][j] != INF || dist[j][i] != INF) cnt++;
        }
        if (cnt == n - 1) answer++;
    }
    
    
    return answer;
}