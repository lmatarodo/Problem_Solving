#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> v;

bool cmp(pair<int, int>& a, pair<int, int>& b) { // 끝나는 시간이 빠른 순으로, 끝나는 시간이 같디면, 시작하는 시간이 빠른 순으로 정렬
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    
    pair<int, int> p;
    while (n--) {
        cin >> p.first >> p.second;
        v.push_back(p);
    }

    sort(v.begin(), v.end(), cmp);

    int st = v[0].first; int en = v[0].second; // 각각 회의 시작시간과 종료시간
    int ans = 1;
    for (int i = 1; i < v.size(); i++) {
        if (v[i].first >= en) { // 만약 회의 시작시간이 이전 회의 종료시간보다 크거나 같다면,
            ans++;
            st = v[i].first; en = v[i].second;
        }
    }

    cout << ans;

    return 0;
}
