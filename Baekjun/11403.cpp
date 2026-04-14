#include <iostream>
#include <vector>

using namespace std;

int n;
const int INF = 1e9;
int dist[102][102];

int main() {
    cin >> n;
    int num;
    // 경로 문제: i == j일 경우에도 사이클을 통해 다시 자기 자신으로 돌아올 수 있는 경우에만 값이 갱신되도록 해야함.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> num;
            if (num == 1) dist[i][j] = 1;
            else if (num == 0) dist[i][j] = INF;
        }
    }

    for (int i = 1; i <= n; i++) { // 경유지
        for (int s = 1; s <= n; s++) { // 출발지
            for (int t = 1; t <= n; t++) { // 도착지
                if (dist[s][t] > dist[s][i] + dist[i][t])
                    dist[s][t] = dist[s][i] + dist[i][t];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) cout << "0 ";
            else cout << "1 ";
        }
        cout << "\n";
    }

    return 0;
}