#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main() {
    cin >> n;
    vector<int> v;
    int num;

    for (int i = 0; i < n; i++) {
        cin >> num;
        if (v.empty()) v.push_back(num);
        if (!v.empty() && v.back() < num) v.push_back(num);
        if (!v.empty() && v.back() >= num) {
            auto it = lower_bound(v.begin(), v.end(), num);
            *it = num;
        }
    }

    cout << v.size();

    return 0;
}