#include <iostream>

using namespace std;

const int ROOT = 1;
int unused = 2;
const int MX = 10000 * 500 + 5; // 최대 등장 가능한 글자의 수
// 만약 문제 조건에서 길이가 최대 500인 문자열이 10000개 들어오는 문제일 경우에 위와 같이 둔다.
bool chk[MX]; // 해당 정점이 문자열의 끝인지 여부를 저장하는 배열
int nxt[MX][26]; // 각 정점에서 자식 정점의 번호를 의미, 문자의 종류 갯수로 열 갯수를 정함(지금은 26개)
// 위와 같이 관리하면 이동해야 하는 자식 정점의 번호를 O(1)에 알 수 있음
// 하지만 메모리를 상당히 많이 차지한다는 단점이 있음

// 글자를 받아 배열의 인덱스로 쓸 수 있게 변환하는 함수
// 만약 소문자도 나온다면 그에 맞게 대응이 되게 변환 필요
int c2i(char c) {
    return c - 'A';
}

void insert(string& s) {
    int cur = ROOT; // cur: 현재 보고 있는 정점 번호를 의미
    for (auto c : s) {
        // 만약 자식 정점이 -1이면 자식이 없다는 것을 의미하므로 unused를 이용해 새로운 정점 번호를 할당해줌
        if (nxt[cur][c2i(c)] == -1) {
            nxt[cur][c2i(c)] = unused++;
        }
        cur = nxt[cur][c2i(c)];
    }
    // 이동이 끝난 후에 문자열의 끝이라고 정해줌
    chk[cur] = true;
}

bool find(string& s) {
    int cur = ROOT;
    for (auto c : s) {
        // 존재하지 않는 자식 정점을 만나면 바로 false를 반환
        if (nxt[cur][c2i(c)] == -1)
            return false;
        cur = nxt[cur][c2i(c)];
    }
    return chk[cur];
}
 
void erase(string& s) {
    int cur = ROOT;
    for (auto c : s) {
        // 만약 존재하지 않는 자식 정점을 만나면 string s가 트라이에 없다는 의미
        // 따라서 return을 통해 그대로 함수를 종료
        if (nxt[cur][c2i(c)] == -1) 
            return;
        cur = nxt[cur][c2i(c)];
    }
    // 마지막 글자에 대응되는 정점에 도달했다면 chk[cur]를 false로 만들어줌
    chk[cur] = false;
}

int main() {

    for (int i = 0; i < MX; i++) 
        fill(nxt[i], nxt[i] + 26, -1);

    return 0;
}