#include <iostream> // 이분탐색 풀이
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<string> enter;
    vector<string> leave;
    vector<string> uni;
    vector<string> ans;

    string name, order;
    for (int i = 0; i < n; i++) {
        cin >> name >> order;
        uni.push_back(name);
        if (order == "enter") enter.push_back(name);
        else leave.push_back(name);
    }
    sort(enter.begin(), enter.end());
    sort(leave.begin(), leave.end());
    sort(uni.begin(), uni.end());

    uni.erase(unique(uni.begin(), uni.end()), uni.end());

    for (int i = 0; i < uni.size(); i++) {
        int enterLen = (upper_bound(enter.begin(), enter.end(), uni[i]) - enter.begin()) - (lower_bound(enter.begin(), enter.end(), uni[i]) - enter.begin());
        int leaveLen = (upper_bound(leave.begin(), leave.end(), uni[i]) - leave.begin()) - (lower_bound(leave.begin(), leave.end(), uni[i]) - leave.begin());

        if (enterLen > leaveLen) ans.push_back(uni[i]);
    }

    sort(ans.begin(), ans.end(), greater<string>());

    for (int i = 0 ; i < ans.size(); i++) cout << ans[i] << '\n';
    return 0;
}
