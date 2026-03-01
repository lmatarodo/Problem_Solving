#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
    int n; // 그래프에 있는 모든 정점들의 수
    vector<int> adj; // 어느 한 정점에 인접한 정점들
    queue<int> q; // 위상 정렬에 사용할 큐
    int deg[10]; // indegree 정도를 채움
    vector<int> result; // 위상 정렬 결과를 저장

    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) q.push(i);
    } // indegree가 0인 정점들을 큐에 넣음

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        result.push_back(cur); // 큐에서 정점을 꺼내어 위상 정렬 결과에 추가

        for (int nxt : adj[cur]) { // 해당 정점에서 연결된 모든 정점
            deg[nxt]--; // 그 모든 정점들의 indegree 값을 1 감소시킴
            if (deg[nxt] == 0) q.push(nxt); // 만약 indegree가 0이 되었다면 그 정점을 큐에 추가
        }

    }

    if (result.size() != n) {
        cout << "cycle exists!";
    } // 만약 위상 정렬 결과에 모든 정점이 포함되어 있지 않다면 그래프 내에 싸이클 존재
    else {
        for (int x: result) cout << x << ' ';
    }
    
}