#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int n, k;
int dist[100002];


int main() {
    fill(dist, dist + 100002, -1);
    cin >> n >> k;
    deque<int> dq;
    dq.push_back(n);
    dist[n] = 0;

    while (!dq.empty()) {
        int cur = dq.front(); dq.pop_front();
        if (cur == k) break; // 목표 도착 시 종료

        // 순간이동 먼저 처리!!
        int nxt_tele = 2 * cur;
        if (nxt_tele <= 100000 && (dist[nxt_tele] == -1 || dist[nxt_tele] > dist[cur])) {
            dist[nxt_tele] = dist[cur];
            dq.push_front(nxt_tele);
        }
        for (int nxt : {cur - 1, cur + 1}) {
            if (nxt < 0 || nxt > 100000) continue;
            if (dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            dq.push_back(nxt);
        } 
    }
    cout << dist[k];

    return 0;
}