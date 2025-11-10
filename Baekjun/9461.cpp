#include <iostream>
#include <vector>

using namespace std;

int T, N;

int main() {
    cin >> T;

    while (T--) {
        vector<long long> pado(101, 0);
        pado[1] = pado[2] = pado[3] = 1;
        pado[4] = pado[5] = 2;
        
        cin >> N;
        for (int i = 6; i <= N; i++) {
            pado[i] = pado[i - 1] + pado[i - 5];
        }
        cout << pado[N] << "\n";

    }

    return 0;
}