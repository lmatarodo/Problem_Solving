#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v;
    int n; cin >> n;

    if (n == 1) return 0;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            v.push_back(i);
            n /= i;
            i--;
        }
    }
    v.push_back(n);

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << '\n';
    return 0;
}
