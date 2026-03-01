#include <iostream>
#include <vector>

using namespace std;

vector<string> croatia = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main() {
    string ipt;
    cin >> ipt;

    // 알파벳 하나하나를 검색
    for (int i = 0; i < croatia.size(); i++) {
        // 해당 알파벳을 모두 지울때까지 반복
        while (true) {
            int pos = ipt.find(croatia[i]);
            // 만약 해당 알파벳이 더 이상 찾아지지 않으면 반복문 종료
            if (pos == -1) break;
            // 해당하는 알파벳을 다른 길이 1인 문자로 대체
            ipt.replace(pos, croatia[i].size(), "#");
        }
    }

    cout << ipt.size();

    return 0;
}