#include <iostream>
#include <queue>

using namespace std;

int dist[100002];

int main() {
    int n, k;
    cin >> n >> k;
    fill(dist, dist + 100002, -1);

    queue<int> q;
    q.push(n); // 수빈이의 시작 위치를 큐에 담음
    dist[n] = 0; // 수빈이의 시작 위치

    while (!q.empty()) {
        int curr = q.front(); // 큐에서 위치 값을 하나 꺼냄
        q.pop();

        // for (int i = 0; i < 3; i++) {
        //     if (i == 0) {
        //         int nx = curr - 1;
        //         if (nx < 0 || nx > 100000 || dist[nx] >= 0) continue;
        //         q.push(nx);
        //         dist[nx] = dist[curr] + 1;
        //     }

        //     else if (i == 1) {
        //         int nx = curr + 1;
        //         if (nx < 0 || nx > 100000 || dist[nx] >= 0) continue;
        //         q.push(nx);
        //         dist[nx] = dist[curr] + 1;
        //     }

        //     else if (i == 2) {
        //         int nx = curr * 2;
        //         if (nx < 0 || nx > 100000 || dist[nx] >= 0) continue;
        //         q.push(nx);
        //         dist[nx] = dist[curr] + 1;
        //     }
        // } 아래쪽에 range-based for loop를 이용해 더 빠르게 해결
        for (int nxt: {curr - 1, curr+ 1, 2* curr}) {
            if (nxt < 0 || nxt > 100000 || dist[nxt] >= 0) continue;
            dist[nxt] = dist[curr] + 1;
            q.push(nxt);
        }
    }

    cout << dist[k];
    return 0;
}