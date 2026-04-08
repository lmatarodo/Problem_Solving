#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define X first
#define Y second

using namespace std;

char field[12][6];
bool visited[12][6];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool chain(int x, int y, char c) {
    int cnt = 1;
    queue<pair<int, int>> q;
    vector<pair<int, int>> puyo_group;
    puyo_group.push_back({x, y});
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
            if (visited[nx][ny] || field[nx][ny] != c) continue;
            cnt++;
            q.push({nx, ny});
            puyo_group.push_back({nx, ny});
            visited[nx][ny] = true;
        }
    }

    if (cnt >= 4) { // 연쇄 반응이 일어나야함
        for (auto p: puyo_group){
            field[p.X][p.Y] = '.';
        }
        return true;
    }
    else {
        return false;
    }

}

void gravity() {
    for (int j = 0; j < 6; j++) { // 각 열에 대하여
        for (int i = 11; i >= 0; i--) {
            if (field[i][j] == '.') {
                for (int k = i - 1; k >= 0; k--) {
                    if (field[k][j] != '.') {
                        field[i][j] = field[k][j];
                        field[k][j] = '.';
                        break;
                    }
                }
            }
        }
    }
}

int main() {

    for (int i = 0; i < 12; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < 6; j++) field[i][j] = str[j];
    }

    int ans = 0;
    while (true) {
        bool is_exploded = false;
        for (int i = 0; i < 12; i++) fill(visited[i], visited[i] + 6, false);

        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if (field[i][j] != '.' && !visited[i][j]) {
                    if (chain(i, j, field[i][j])) {
                        is_exploded = true;
                    }
                }
            }
        }
        if (!is_exploded) break;
        ans++;
        gravity();

    }
    cout << ans;
    return 0;
}