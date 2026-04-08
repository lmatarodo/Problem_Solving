#include <iostream>
#include <queue>

using namespace std;

int n;
long long x;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<long long> pq;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 0) {
            if (pq.empty()) {
                cout << 0 << "\n";
                continue;
            }
            cout << pq.top() << "\n"; pq.pop();
        }
        else {
            pq.push(x);
        }
    }
    return 0;
}