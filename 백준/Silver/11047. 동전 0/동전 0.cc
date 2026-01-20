#include <iostream>

using namespace std;
int a[1000002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int sum = 0;

    for (int i = n; i >= 1; i--) {
        if (a[i] <= k) { // a_i가 k보다 처음으로 작아지는 시점이 오면,

            sum += k / a[i];
            k = k % a[i];
            
            if (k % a[i] == 0) break;
        }
    }

    cout << sum;

    return 0;
}
