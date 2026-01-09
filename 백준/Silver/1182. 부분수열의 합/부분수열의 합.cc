#include <iostream>

using namespace std;

int n, s;
int cnt = 0;
int arr[22];
bool isused[22];
int sum = 0;

void func(int idx) {
    if (idx == n) {
        return;
    }

    for (int i = idx; i < n; i++) {
        if (!isused[i]) {
            sum += arr[i];
            if (sum == s)
                cnt++;
            isused[i] = true;
            func(i + 1);
            sum -= arr[i];
            isused[i] = false;
        }
    }
}

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    func(0);
    cout << cnt;
    return 0;
}