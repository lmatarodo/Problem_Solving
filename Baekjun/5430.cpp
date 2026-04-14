#include <iostream>
#include <cctype>
#include <deque>
#include <algorithm>

using namespace std;

int t;

bool func(char c, deque<int>& x, bool& isReverse) {
    if (c == 'R') {
        isReverse = !isReverse;
        return true;
    }

    else if (c == 'D') {
        if (x.empty()) return false;

        if (!isReverse)
            x.pop_front();
        else
            x.pop_back();
        return true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for (int test_case = 0; test_case < t; test_case++) {
        int n;
        string p, xstr;
        cin >> p >> n >> xstr;
        deque<int> x;
        for (int i = 0; i < xstr.size(); i++) {
            if (isdigit(xstr[i])) {
                string temp = "";
                while (isdigit(xstr[i]) && i < xstr.size()) {
                    temp += xstr[i];
                    i++;
                }
                x.push_back(stoi(temp));
                i--;
            }
        }

        bool isNormal;
        bool isReverse = false;
        for (int i = 0; i < p.size(); i++) {
            isNormal = func(p[i], x, isReverse);
            if (!isNormal) {
                cout << "error\n";
                break;
            }
        }

        if (isReverse) reverse(x.begin(), x.end());

        if (isNormal) {
            cout << '[';
            if (!x.empty()) {
                for (int i = 0; i < x.size() - 1; i++) {
                    cout << x[i] << ',';
                }
                cout << x[x.size() - 1];
            }
            cout << "]\n";
        }
    }

    return 0;
}