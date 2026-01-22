#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int a[500002];

int lower_idx(int target, int len) {
    int st = 0;
    int en = len;
    while (st < en) {
        int mid = (st + en) / 2;
        if (a[mid] >= target) en = mid;
        else st = mid + 1;
    }
    return st;
}

int upper_idx(int target, int len) {
    int st = 0;
    int en = len;
    while (st < en) {
        int mid = (st + en) / 2;
        if (a[mid] > target) en = mid;
        else st = mid + 1;
    }
    return st;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    
    cin >> m;
    int num;
    while (m--) {
        cin >> num;
        cout << upper_idx(num, n) - lower_idx(num, n) << '\n';
    }


    return 0;
}
