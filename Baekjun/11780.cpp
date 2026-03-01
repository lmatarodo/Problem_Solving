#include <iostream>
#include <vector>

using namespace std;

int n, m;
int INF = 1e9;
int dist[102][102];
int nxt[102][102];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        dist[a][b] = min(dist[a][b], cost);
        nxt[a][b] = b;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    nxt[i][j] = nxt[i][k]; // nxt[s][t]를 nxt[s][k]로 교체
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) cout << 0 << ' ';
            else cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int i = 1; i <=n; i++) {
        for (int j = 1; j <= n; j++) { // i에서 j로 가는 최단 경로를 찾아야함
            if (dist[i][j] == 0 || dist[i][j] == INF) {
                cout << 0 << '\n';
                continue;
            }
                
            vector<int> path; // 경로를 저장하는 벡터 배열 선언
            int next = i; // 그 다음 경로를 저장
            while (next != j) { // 목적지에 도달할 때까지
                path.push_back(next);
                next = nxt[next][j]; // 그 다음 노드를 경로에 추가
            }
            path.push_back(j); // 최종 목적지를 경로에 추가
            cout << path.size() << ' ';
            for (int k = 0; k < path.size(); k++) cout << path[k] << ' ';
            cout << '\n';
            
        }
    }

    return 0;
}