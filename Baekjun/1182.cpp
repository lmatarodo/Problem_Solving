#include <iostream>

using namespace std;

int n, s;
int cnt = 0;
int arr[22];

void func(int idx, int total) {
    if (idx == n) {
        if (total == s)
            cnt++;
        return;
    }

    func(idx + 1, total);
    func(idx + 1, total + arr[idx]);
}

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    func(0, 0);
    if (s == 0) cnt - 1;
    cout << cnt;
    return 0;
}