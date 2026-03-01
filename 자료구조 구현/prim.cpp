#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define X first
#define Y second

int main() {

    int v, e;
    // 비용, 정점 번호
    vector<pair<int, int>> adj[10005];
    priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq;
    bool chk[10005]; // 해당 정점이 최소 신장 트리에 속해있는지를 체크
    int cnt = 0; // 현재 최소 신장 트리에 속해있는 정점 수

    chk[1] = true; // 임의의 정점을 최소신장트리에 추가
    for (auto nxt: adj[1]) // 해당 정점과 연결된 모든 간선을 우선순위 큐에 추가
        pq.push({nxt.X, 1, nxt.Y});

    while (cnt < v - 1) { // v - 1개의 간선이 추가될때까지 반복 
        int cost, a, b;
        tie(cost, a, b) = pq.top(); pq.pop();
        if (chk[b]) continue; // 만약 해당 간선이 최소 신장 트리에 포함된 두 정점을 연결한다면 아무것도 하지 않고 넘어감 
        cout << cost << ' ' << a << ' ' << b << '\n';
        chk[b] = true; // 정점 v를 최소 신장 트리에 추가 후
        cnt++;
        // 정점 v와 최소 신장 트리에 포함되지 않는 정점을 연결하는 모든 간선을 우선순위 큐에 추가
        for (auto nxt: adj[b]) {
            if (!chk[nxt.Y])
                pq.push({nxt.X, b, nxt.Y});
        }
    }


}