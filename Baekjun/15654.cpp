#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[10];
int ipt[10];

void func(int k, int start) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = start; i < n; i++) {
        arr[k] = ipt[i];
        func(k + 1, i + 1);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> ipt[i];
    }
    sort(ipt, ipt + n);
    func(0, 0);
    return 0;
}