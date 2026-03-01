#include <iostream>
#include <unordered_set>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;

    string str;
    unordered_set<string> s;
    for (int i = 0; i < n; i++) {
        cin >> str;
        s.insert(str);
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        cin >> str;
        if (s.find(str) != s.end()) ans++;
    }
    cout << ans;

    return 0;
}