#include <iostream>

using namespace std;

int n, m;
const int ROOT = 1;
int unused = 2;
const int MX = 500 * 10000 + 5;
int nxt[MX][26];
bool chk[MX];

int c2i(char c) {
    return c - 'a';
}

void insert(string& s) {
    int cur = ROOT;
    for (char c: s) {
        if (nxt[cur][c2i(c)] == -1) {
            nxt[cur][c2i(c)] = unused++;
        }
        cur = nxt[cur][c2i(c)];
    }
    chk[cur] = true;
}

bool find(string& s) {
    int cur = ROOT;
    for (char c: s) {
        if (nxt[cur][c2i(c)] == -1)
            return false;
        cur = nxt[cur][c2i(c)];

    }
    return chk[cur];
}

void erase(string& s) {
    int cur = ROOT;
    for (char c: s) {
        if (nxt[cur][c2i(c)] == -1)
            return;
        cur = nxt[cur][c2i(c)];

    }
    chk[cur] = false;
}

int main() {
    for (int i = 0; i < MX; i++)
        fill(nxt[i], nxt[i] + 26, -1);
    cin >> n >> m;
    
    string ipt;
    for (int i = 0; i < n; i++) {
        cin >> ipt; insert(ipt);
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        cin >> ipt;
        if (find(ipt)) ans++;
    }
    cout << ans;

    return 0;
}