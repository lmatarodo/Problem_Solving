#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int d[101][100001];
int w[101];
int v[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) 
        cin >> w[i] >> v[i];
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j < w[i]) d[i][j] = d[i - 1][j];
            else {
                d[i][j] = max(d[i - 1][j], d[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    cout << d[n][k];

    return 0;
}
