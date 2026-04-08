#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int k, l;

int main() {

    unordered_map<string, int> system;
    vector<pair<int, string>> v;

    cin >> k >> l;
    for (int i = 0; i < l; i++) {
        string stnum;
        cin >> stnum;
        system[stnum] = i;
    }

    for (auto e: system) {
        v.push_back({e.second, e.first});
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size() && i < k; i++)
        cout << v[i].second << "\n";

    return 0;
}