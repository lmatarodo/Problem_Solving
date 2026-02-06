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
        if (y == n) y = 0; // y가 n일 경우, 나머지를 0으로 만들어주어야함]
        int l = lcm(m, n); // for문 안에서 lcm을 계속 계산하는 것을 방지하기 위해 미리 게산해줌
        for (int i = x; i <= l; i += m) {
            if (i % n == y) {
                cout << i << '\n'; 
                isvalid = true;
                break;
            }
        }
        if (!isvalid) cout << "-1\n";
    }


    return 0;
}
