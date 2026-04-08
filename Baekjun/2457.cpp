#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n;
vector<pair<int, int>> v;

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        int stm, std, enm, end;
        cin >> stm >> std >> enm >> end;
        int stdate = stm * 100 + std;
        int endate = enm * 100 + end;
        v.push_back({stdate, endate});
    }

    sort(v.begin(), v.end());
    
    int cur = 301;
    int idx = 0;
    int answer = 0; 
    
    while (cur <= 1130) {
        int maxEnd = cur;
        while (idx < n && v[idx].first <= cur) {
            maxEnd = max(maxEnd, v[idx].second);
            idx++;
        }

        if (maxEnd == cur) {
            cout << 0;
            return 0;
        }

        cur = maxEnd;
        answer++;
    }

    cout << answer;
    return 0;
}