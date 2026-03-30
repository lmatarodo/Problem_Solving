#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int main() {

    unordered_map<string, vector<string>> group; // 걸그룹, 소속된 팀원들
    unordered_map<string, string> member; // 멤버 이름, 소속된 걸그룹 명
    string groupname; string membername;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> groupname;
        int teamnum; cin >> teamnum;
        for (int j = 0; j < teamnum; j++) {
            cin >> membername;
            group[groupname].push_back(membername);
            member[membername] = groupname;
        }
    }

    int type;
    string question;
    for (int i = 0; i < m; i++) {
        cin >> question >> type;
        if (type == 0) {
            vector<string> ans;
            for (auto e: group[question]) {
                ans.push_back(e);
            }
            sort(ans.begin(), ans.end());
            for (auto e: ans)
                cout << e << "\n";

        }
        else if (type == 1) {
            cout << member[question] << "\n";
        }
    }

}
