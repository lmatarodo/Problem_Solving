#include <iostream>

using namespace std;

bool isused1[32];
bool isused2[32];
bool isused3[32]; // 아직 놓지 않은 상태가 false

int n;
int cnt = 0;

void func(int curr) {
    if (curr == n) {
        cnt++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!isused1[i] && !isused2[i + curr] && !isused3[curr - i + n - 1]) { // x : curr, y : i , 새로운 퀸을 놓을 수 있음
            isused1[i] = true;
            isused2[curr + i] = true;
            isused3[curr - i + n - 1] = true;

            func(curr + 1);

            isused1[i] = false;
            isused2[curr + i] = false;
            isused3[curr - i + n - 1] = false;

        }
    }
}

int main() {
    cin >> n;
    func(0);
    cout << cnt;
    return 0;
}