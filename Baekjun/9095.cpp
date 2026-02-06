#include <iostream>

using namespace std;

int t, num;
int d[13];

int main() {

    cin >> t;

    d[1] = 1; d[2] = 2; d[3] = 4;

    for (int i = 4; i <= 11; i++) {
        d[i] = d[i - 1] + d[i - 2] + d[i - 3];
    }
    while (t--) {
        cin >> num;
        cout << d[num] << '\n';
    }
    return 0;
}