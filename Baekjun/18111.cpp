#include <iostream>
#include <algorithm>

using namespace std;

int n, m, b;
int height[257];
const int max_val = 1e9;

int main() {

    cin >> n >> m >> b;

    int minH = max_val;
    int maxH = -1;
    for (int i = 0; i < n * m; i++) {
        int h; cin >> h;
        height[h]++;
        if (h > maxH) maxH = h;
        if (h < minH) minH = h;
    }
    int remove = 0;
    int need = 0;
    int minTime = max_val;
    int resultH;

    for (int h = maxH; h >= minH; h--) {
        remove = 0;
        need = 0;
        for (int i = 0; i <= 256; i++) {
            if (height[i] == 0) continue;
            if (i > h) remove += (i - h) * height[i];
            else if (i < h) need += (h - i) * height[i];
        }

        if (b + remove - need >= 0) {
            int curTime = 2 * remove + need;
            if (curTime < minTime) {
                minTime = curTime;
                resultH = h;
            }
        }
    }

    cout << minTime << " " << resultH;

    return 0;
}