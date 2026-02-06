#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    unordered_set<string> s;
    vector<string> v;
    string name; string move;

    while (n--) {
        cin >> name >> move;
        if (move == "enter" && s.find(name) == s.end()) { // 만약 삽입시에 찾고자 하는 이름이 없으면,
            s.insert(name);
        }
        else if (move == "leave" && s.find(name) != s.end()) { // 만약 삭제 시에 삭제하고자 하는 이름이 있으면,
            s.erase(name);
        }
    }

    for (auto e : s) v.push_back(e); // 정렬을 위해 벡터로 복사
    sort(v.begin(), v.end(), greater<string>()); // 사전 내림차순으로 정렬
    for (auto e : v) cout << e << "\n";

    return 0;
}
