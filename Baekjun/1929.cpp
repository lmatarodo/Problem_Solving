#include <iostream>
#include <vector>

using namespace std;

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;

    vector<int> prime;
    vector<bool> state(n + 1, true);
    state[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (!state[i]) continue;
        for (int j = i * i; j <= n; j += i)
            state[j] = false;
    }

    for (int i = m; i <= n; i++)
        if (state[i]) prime.push_back(i);

    for (int i = 0; i < prime.size(); i++)
        cout << prime[i] << '\n';
    return 0;
}
