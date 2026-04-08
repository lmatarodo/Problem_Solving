#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main() {

    int a, b, c;
    int mindp[3] = {0, 0, 0};
    int maxdp[3] = {0, 0, 0};

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;

        if (i == 0) {
            mindp[0] = a; mindp[1] = b; mindp[2] = c;
            maxdp[0] = a; maxdp[1] = b; maxdp[2] = c;
        }

        else {
            int prevmin0 = mindp[0]; int prevmin1 = mindp[1]; int prevmin2 = mindp[2];
            int prevmax0 = maxdp[0]; int prevmax1 = maxdp[1]; int prevmax2 = maxdp[2];

            mindp[0] = min(prevmin0, prevmin1) + a;
            mindp[1] = min({prevmin0, prevmin1, prevmin2}) + b;
            mindp[2] = min(prevmin1, prevmin2) + c;

            maxdp[0] = max(prevmax0, prevmax1) + a;
            maxdp[1] = max({prevmax0, prevmax1, prevmax2}) + b;
            maxdp[2] = max(prevmax1, prevmax2) + c;           
        }
    }
    int maxscore = max({maxdp[0], maxdp[1], maxdp[2]});
    int minscore = min({mindp[0], mindp[1], mindp[2]});

    cout << maxscore << " " << minscore;
    return 0;
}