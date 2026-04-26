#include <iostream>

using namespace std;

int n;
int odds[5] = {1, 3, 5, 7, 9};
int fDigit[4] = {2, 3, 5, 7};

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void dfs(int depth, string cur) {
    if (depth == n) {
        cout << cur << "\n";
        return;       
    }

    if (depth == 0) {
        for (int f: fDigit) {
            cur.push_back(f + '0');
            dfs(1, cur);
            cur.pop_back();
        }
    }

    if (depth > 0) {
        for (int o: odds) {
            cur.push_back(o + '0');
            if (isPrime(stoi(cur))) {
                dfs(depth + 1, cur);
            }
            cur.pop_back();
        }
    }
}

int main() {
    cin >> n;
    string cur = "";
    dfs(0, cur);
    return 0;
}