#include <iostream>

using namespace std;

int n, m;
int dist[102][102]; // 도시 i에서 j로 가는 최솟값
int INF = 1e9; // 전체 도시가 100개이고 각 간선 비용이 100000이라면 1e9 이상까지 최대 비용이 나올수도 있음

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <=n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for (int i = 0; i < m ; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        dist[a][b] = min(cost, dist[a][b]);
        // 문제에서 각 도시를 연결하는 노선은 하나가 아닐 수도 있다는 조건을 두었기 떼문
    }

    // 플로이드 알고리즘
    for (int i = 1; i <= n; i++) { // 경유지
        for (int s = 1; s <= n; s++) { // 출발지
            for (int t = 1; t <= n; t++) { // 도착지
                if (dist[s][i] + dist[i][t] < dist[s][t]) 
                    dist[s][t] = dist[s][i] + dist[i][t];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if (dist[i][j] == INF) cout << 0 << ' '; // 갈 수 없는 경우에 0을 출력해야 함
            else cout << dist[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}