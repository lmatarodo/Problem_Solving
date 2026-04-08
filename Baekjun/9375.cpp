#include <iostream>
#include <unordered_map>

using namespace std;

int t, n;

int main() {
    string clothe; string type;
    cin >> t;
    for (int i = 0; i < t; i++) {
        unordered_map<string, int> wear;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> clothe >> type;
            wear[type]++;
        }

        int total = 1;
        for (auto e: wear) {
            total *= (e.second + 1);
        }
        cout << total - 1 << "\n";
    }

    return 0;
}