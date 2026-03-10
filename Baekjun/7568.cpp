#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> ans;
vector<pair<int, int>> v;


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int w, h;
        cin >> w >> h;
        v.push_back({w, h});
    }

    for (int i = 0; i < n; i++) {
        int cnt = 1;
        for (int j = 0; j < n; j++) {
            if (v[i].first < v[j].first && v[i].second < v[j].second) cnt++;
        }
        ans.push_back(cnt);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }


    return 0;
}