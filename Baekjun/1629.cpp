#include <iostream>

using namespace std;

using ll = long long;


int func(ll a, ll b, ll m) {
    if (b == 1) return a % m;
    ll val = func(a, b / 2, m);
    val = val * val % m;
    if (b % 2 == 0) return val;
    return val * a % m;
}

int main() {

    ll a, b, m;
    cin >> a >> b >> m;

    ll answer = func(a, b, m);
    cout << answer;
    return 0;
}