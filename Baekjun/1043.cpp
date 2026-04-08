#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, truth;
vector<int> adj[52];
bool visited[52];
vector<vector<int>> parties;

int main() {
    cin >> n >> m;
    cin >> truth;
    queue<int> q;
    for (int i = 0; i < truth; i++) {
        int t; cin >> t;
        visited[t] = true;
        q.push(t); // 진실을 아는 사람을 bfs 시작점으로 넣음
    }

    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        vector<int> party(num);
        for (int j = 0; j < num; j++){
            cin >> party[j];
        }
        parties.push_back(party);

        for (int j = 1; j < num; j++) {
            adj[party[0]].push_back(party[j]);
            adj[party[j]].push_back(party[0]);
        }
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt: adj[cur]) {
            if (!visited[nxt]) {
                visited[nxt] = true;
                q.push(nxt);
            }
        }
    }

    int answer =.0; 
    for (auto party: parties) {
        bool canLie = true;
        for (int person: party) {
            if (visited[person]) {
                canLie = false;
                break;
            }
        }

        if (canLie) answer++;
    }

    cout << answer;

    return 0;
}