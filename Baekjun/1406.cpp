#include <iostream>

using namespace std;

const int MX = 1000005;
char dat[MX];
int pre[MX], nxt[MX];
int unused  = 1; 

void insert(int addr, int num) {
    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if(nxt[unused] != -1) pre[nxt[unused]] = unused;
    nxt[addr] = unused;
    unused++;
}

void erase(int addr) {
    if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
    nxt[pre[addr]] = nxt[addr];
}

void traversal() {
    int cur = nxt[0];
    while (cur != -1){
        cout << dat[cur];
        cur = nxt[cur];
    }
    cout << "\n\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);
    string s;
    cin >> s;
    int cursor = 0;
    for (auto c: s) {
        insert(cursor, c);
        cursor++;
    }

    int M;
    cin >> M;
    while (M--) {
        char order;
        cin >> order;
        
        if (order == 'P') {
            char plus;
            cin >> plus;
            insert(cursor, plus);
            cursor = nxt[cursor];
        }

        else if (order == 'L') {
            if (pre[cursor] != -1){
                cursor = pre[cursor];
            }
        }

        else if (order == 'D') {
            if (nxt[cursor] != -1){
                cursor = nxt[cursor];
            }
        }

        else {
            if (pre[cursor] != -1) {
                erase(cursor);
                cursor = pre[cursor];
            }

        }
    }
    traversal();
    return 0;
}