#include <iostream>
#include <algorithm>

using namespace std;

int d[1000002]; // 안에 들어있는 숫자를 1로 만들기 위해 필요한 연산 사용 횟수의 최솟값
int n;

int main() {

    cin >> n;

    for (int i = 2; i <=n; i++) {
        int d1 = 1e6; int d2 = 1e6; int d3 = 0; // 각각 d[i]가 될 수 있는 후보값
        if (i % 2 == 0) {
            d1 = d[i / 2] + 1;
        }

        if (i % 3 == 0) {
            d2 = d[i / 3] + 1;
        }
        d3 = d[i - 1] + 1;

        d[i] = min({d1, d2, d3});
    }

    cout << d[n];

    return 0;
}