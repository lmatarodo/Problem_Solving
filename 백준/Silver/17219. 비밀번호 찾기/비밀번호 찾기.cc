#include <iostream>
#include <unordered_map>

using namespace std;

int n, m;

int main() {
    unordered_map<string, string> memo; // 사이트 주소, 비밀번호
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string address; string password;
        cin >> address >> password;
        memo[address] = password;
    }

    for (int i = 0; i < m; i++) {
        string input;
        cin >> input;
        cout << memo[input] << "\n";
    }

    return 0;
}