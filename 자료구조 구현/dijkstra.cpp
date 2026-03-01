#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V = 10; // 정점 갯수
const int INF = 0x7fffffff;
int dist[100002];
bool fix[100002]; // 최단 거리가 확정되었는지 여부를 관리
vector<pair<int,int>> adj[100002]; // 정점 번호, 비용

void dijstra(int st) {
    fill(dist, dist + 100002, INF);
    fill(fix, fix + 100002, false);
    dist[st] = 0;
    while (true) {
        int idx = -1;
        // 아직 방문하지 않은 노드 중 거리가 가장 짧은 것을 선택
        for (int i = 1; i <= V; i++) {
            if (fix[i]) continue;
            if (idx == -1) idx = i;
            else if (dist[idx] > dist[i]) idx = i;
        }
        if (idx == -1 || dist[idx] == INF) break; // 더 이상 선택할 수 있는 정점이 없으면 종료
        fix[idx] = true; // 해당 정점의 최단 거리를 확정
        // 선택된 정점과 인접한 정점의 거리를 갱신
        for (auto nxt : adj[idx]) {
            dist[nxt.first] = min(dist[nxt.first], dist[idx] + nxt.second);
        }
    }
}

int main() {

    return 0;
}