#include <iostream>

using namespace std;

int n, m;
int r, c, d;
int room[52][52];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin >> n >> m;
    cin >> r >> c >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            cin >> room[i][j];
    }

    int answer = 0; // 작동을 멈출 때까지 청소하는 칸의 갯수 
    while (true) {
        if (room[r][c] == 0) {
            room[r][c] = 2;
            answer++; // 청소되지 않은 경우, 청소한 상태로 만들어줌
        }
        else { // 이미 청소한 경우,
            bool isDirty = false;
            for (int dir = 0; dir < 4; dir++) { // 동서남북에 대하여 확인
                int nr = r + dx[dir];
                int nc = c + dy[dir];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if (room[nr][nc] == 0) isDirty = true;
            }

            if (!isDirty) { // 주변 4칸 중 청소되지 않은 빈 칸이 없음
                if (d == 0) {
                    r++;
                    // 만약 후진 시에 범위를 벗어났거나 벽을 만났다면, 반복문 종료
                    if (r >= n || room[r][c] == 1) break;
                }
                else if (d == 1) {
                    c--;
                    if (c < 0 || room[r][c] == 1) break;
                }
                else if (d == 2) {
                    r--;
                    if (r < 0 || room[r][c] == 1) break;
                }
                else if (d == 3) {
                    c++;
                    if (c >= m || room[r][c] == 1) break;
                }
            }

            if (isDirty) { // 주변 4칸 중 청소되지 않은 빈 칸이 있음
                if (d == 0) {
                    d = 3; // 방향은 무조건 꺾어야함
                    if (c - 1 >= 0 && room[r][c - 1] == 0) {
                        c--; continue;
                    } 
                }
                if (d == 1) {
                    d = 0;
                    if (r - 1 >= 0 && room[r - 1][c] == 0) {
                        r--; continue;
                    }
                }
                if (d == 2) {
                    d = 1;
                    if (c + 1 < m && room[r][c + 1] == 0) {
                        c++; continue;
                    }
                }
                if (d == 3) {
                    d = 2;
                    if (r + 1 < n && room[r + 1][c] == 0) {
                        r++; continue;
                    }
                }
            }
        }
    }

    cout << answer;
    return 0;
}