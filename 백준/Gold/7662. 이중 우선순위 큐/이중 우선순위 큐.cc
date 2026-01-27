#include <iostream>
#include <set>

using namespace std;

int t, k, num;
char c;

int main() {
    cin >> t;
    while (t--) {
        cin >> k;
        multiset<int> ms;
        while (k--) {
            cin >> c >> num;
            if (c== 'I') {
                ms.insert(num);
            }
            else if (c == 'D') {
                if (ms.empty()) continue;
                else if (num == 1) 
                    ms.erase(prev(ms.end()));
                else if (num == -1) {
                    ms.erase(ms.begin());
                }
            }

        }
        if (ms.size() == 0) cout << "EMPTY" << '\n';
        else {
            cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
        }
    }
    return 0;
}