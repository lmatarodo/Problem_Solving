#include <iostream>
#include <vector>

using namespace std;


// 문자열 s를 받아 구분자 sep를 기준으로 문자열을 나눈 결과를 반환
vector<string> split(string& s, string& sep) {
    vector<string> ret;
    int pos = 0;
    while (pos < s.size()) { // 찾을 위치가 문자열 위치를 초과하지 않을때까지 반복
        // 아래와 같이 find 함수의 두번째 인자로 처음 탐색을 시작할 위치를 지정할 수 있음
        int next_pos = s.find(sep, pos);
        // sep가 찾아지지 않으면 마지막 위치 반환
        if (next_pos == -1) next_pos = s.size();
        // 만약 찾아진 위치가 0보다 크다면 반환 벡터 업데이트
        if (next_pos - pos > 0)
            // substr의 첫번째 인자는 시작할 위치의 인덱스를 의미하고,
            // substr의 두번째 인자는 추출할 문자의 갯수를 의미함
            // 따라서 두번째 인자로 next_pos - pos로 두어야한다는 것에 주의
            ret.push_back(s.substr(pos, next_pos - pos));
        // 다음 찾을 위치 업데이트
        pos = next_pos + sep.size();
    }
    return ret;
}

int main() {

    return 0;
}