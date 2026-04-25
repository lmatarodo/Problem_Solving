#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int k;
int wheels[4][8];
int isRotate[4]; // 0: 정지, 1: 시계, -1: 반시계

void rotateUnit(int wheelNum, int dir) {
    if (dir == 1) { // 시계방향으로 회전
        int temp = wheels[wheelNum][7];
        for (int i = 7; i > 0; i--) 
            wheels[wheelNum][i] = wheels[wheelNum][i - 1];
        wheels[wheelNum][0] = temp;
    }

    else if (dir == -1) {
        int temp = wheels[wheelNum][0];
        for (int i = 0; i < 7; i++) 
            wheels[wheelNum][i] = wheels[wheelNum][i + 1];
        wheels[wheelNum][7] = temp;
    }
}

void rotateWheels(int wheelNum, int dir) {
    fill(isRotate, isRotate + 4, 0);
    isRotate[wheelNum] = dir;

    // 현재 돌려야 하는 바퀴 인덱스보다 높은 것들의 회전 방향을 정함
    for (int i = wheelNum; i < 3; i++) {
        if (wheels[i + 1][6] != wheels[i][2]) 
            isRotate[i + 1] = -isRotate[i];
        else break; // 인접한 극성이 같으면 더 이상 전파되지 않음
    }

    // 현재 돌려야 하는 바퀴 인덱스보다 낮은 것들의 회전 방향을 정함
    for (int i = wheelNum; i > 0; i--) {
        if (wheels[i - 1][2] != wheels[i][6]) 
            isRotate[i - 1] = -isRotate[i];
        else break;
    }
}


int main() {
    string input;
    for (int i = 0; i < 4; i++) {
        cin >> input;
        for (int j = 0; j < 8; j++) {
            wheels[i][j] = input[j] - '0';
        }
    }
    
    cin >> k;
    int wheelNum, dir;
    for (int i = 0; i < k; i++) {
        cin >> wheelNum >> dir;
        rotateWheels(wheelNum - 1, dir);
        for (int j = 0; j < 4; j++) {
            rotateUnit(j, isRotate[j]);
        }
    }

    int score = 0;
    for (int i = 0; i < 4; i++) {
        if (wheels[i][0] == 1) 
            score += pow(2, i);
    }
    cout << score;

    return 0;
}