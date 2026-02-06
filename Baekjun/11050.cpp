#include <iostream>

using namespace std;

int factorial(int n) {
    int ans = 1;
    for (int i = n; i >= 1; i--)
        ans *= i;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    cout << factorial(n) / (factorial(n - k) * factorial(k));
    return 0;
}
