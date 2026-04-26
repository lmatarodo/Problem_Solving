#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<long long> result;

// num: 현재까지 만들어진 숫자, last: 마지막에 넣은 숫자
void dfs(long long num, int last) {
    result.push_back(num);

    // last가 0일 때가 재귀의 끝 역할을 대신하므로 return 문이 필요하지 않음
    // 그리고 모든 자리의 숫자를 모두 저장해야 하므로 return 문이 또한 필요하지 않음
    for (int i = 0; i < last; i++) {
        dfs(num * 10 + i, i);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < 10; i++) {
        dfs(i, i);
    }

    sort(result.begin(), result.end());

    if (n >= result.size())
        cout << -1;
    else
        cout << result[n];
    return 0;
}