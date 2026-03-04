#include <iostream>

using namespace std;

int n;
int ans[3]; // -1, 0, 1
int arr[3000][3000];

bool isSame(int x, int y, int size) {
    int init = arr[x][y];
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++)
            if (init != arr[i][j]) return false;
    }
    return true;
}

void func(int x, int y, int size) {
    if (isSame(x, y, size)) {
        ans[arr[x][y] + 1]++;
        return;
    }

    int next = size / 3;
    for (int dx = 0; dx < 3; dx++) {
        for (int dy = 0; dy < 3; dy++) {
            func(x + dx * next, y + dy * next, next);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0;i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }

    func(0, 0, n);
    for (int i = 0; i < 3; i++)
        cout << ans[i] << "\n";

}