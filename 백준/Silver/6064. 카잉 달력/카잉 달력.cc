#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b){
    return a / gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, m, n, x, y;
    cin >> t;
    while (t--) {
        bool isvalid = false;
        cin >> m >> n >> x >> y;
        if (y == n) y = 0;
        for (int i = x; i <= lcm(m, n); i += m) {
            if (i % n == y) {
                cout << i << '\n'; 
                isvalid = true;
            }
        }
        if (!isvalid) cout << "-1\n";
    }


    return 0;
}
