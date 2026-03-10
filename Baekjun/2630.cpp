#include <iostream>

using namespace std;

int n;
int cnt0 = 0; int cnt1 = 0;
int arr[130][130];

bool isFull(int x, int y, int size) {
    int first = arr[x][y];
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++)
            if (first != arr[i][j]) return false;
    }
    return true;
}

void func(int x, int y, int size) {

    if (isFull(x, y, size)) {
        if (arr[x][y] == 0) cnt0++;
        else cnt1++;
        return;
    }

    int next = size / 2;
    for (int dx = 0; dx < 2; dx++) {
        for (int dy = 0; dy < 2; dy++)
            func(x + dx * next, y + dy * next, next);
    }

}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }

    func(0, 0, n);
    cout << cnt0 << "\n" << cnt1;

    return 0;
}