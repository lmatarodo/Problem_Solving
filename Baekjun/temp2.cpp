#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, k;
int visited[100002];

int main() {

    queue<int> q;
    fill(visited, visited + 100002, -1);
    cin >> n >> k;

    q.push(n);
    visited[n] = 0;

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        if (cur == k) {
            cout << visited[cur];
            return 0;
        }

        for (int nxt: {cur - 1, cur + 1, 2 * cur}) {
            if (nxt < 0 || nxt > 100000) continue;
            if (visited[nxt] >= 0) continue;

            q.push(nxt);
            visited[nxt] = visited[cur] + 1;

        }
    }
    return 0;
}