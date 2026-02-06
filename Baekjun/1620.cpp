#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, int> sToi;
    string iTos[100005];

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> iTos[i];
        sToi[iTos[i]] = i;
    }

    string order;
    while (m--) {
        cin >> order;
        if(isdigit(order[0])) { // 주어진 명령이 숫자임
            cout << iTos[(stoi(order))] << '\n';
        }
        else {
            cout << sToi[order] << '\n';
        }
    }

    return 0;
}
