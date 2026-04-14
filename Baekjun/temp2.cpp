#include <iostream>

using namespace std;

int n, m;
string s;

int main() {
    cin >> n >> m;
    cin >> s;

    int cnt = 0;
    for (int i = 0; i < m - 2; i++) {
        if (s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I') {
            int pcnt = 0;
            while (s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I') {
                pcnt++;
                if (pcnt >= n) cnt++;
                i += 2;
                if (i >= m -2) break;
            }
        }
    }
    cout << cnt;
    return 0;
}