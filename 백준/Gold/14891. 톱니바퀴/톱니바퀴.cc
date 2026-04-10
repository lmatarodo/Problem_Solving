#include <iostream>
#include <cmath>

using namespace std;

int k;
int wheels[4][8];

void rotateUnit(int idx, int dir) {
    if (dir == 0) return;

    if (dir == 1) {
        int temp = wheels[idx][7];
        for (int i = 7; i > 0; i--)
            wheels[idx][i] = wheels[idx][i - 1];
        wheels[idx][0] = temp;
    }
    else if (dir == -1) {
        int temp = wheels[idx][0];
        for (int i = 0; i < 7; i++) 
            wheels[idx][i] = wheels[idx][i + 1];
        wheels[idx][7] = temp;
    }
}

// 핵심 아이디어: 회전 방향을 미리 저장해두고 실제 상태 변경은 나중에 하자!
void rotateWheel(int startIdx, int dir) {

    int dirs[4] = {0, }; // 각 바퀴의 회전 방향을 저장
    dirs[startIdx] = dir;

    for (int i = startIdx; i < 3; i++) {
        if (wheels[i][2] != wheels[i + 1][6]) {
            dirs[i + 1] = -dirs[i];
        }
        else break;
    }

    for (int i = startIdx; i > 0; i--) {
        if (wheels[i - 1][2] != wheels[i][6]) {
            dirs[i - 1] = -dirs[i];
        }
        else break;
    }

    for (int i = 0; i < 4; i++) {
        rotateUnit(i, dirs[i]);
    }
}

int main() {
    string wheel;
    for (int i = 0; i < 4; i++) {
        cin >> wheel;
        for (int j = 0; j < 8; j++) {
            wheels[i][j] = wheel[j] - '0';
        }
    }

    cin >> k;
    int startIdx, dir;
    for (int i = 0; i < k; i++) {
        cin >> startIdx >> dir;
        rotateWheel(startIdx - 1, dir);
    }
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        if (wheels[i][0] == 1){
            ans += pow(2, i);
        }
    }
    cout << ans;

    return 0;
}