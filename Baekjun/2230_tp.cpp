#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int st = 0; int en = 0;
    int min = 0x7fffffff;

    while (st < n) {
        while (en < n && a[en] - a[st] < m) en++;// 차이가 m 미만인 동안 en을 뒤로 보냄
        if (en == n) break; // en이 범위를 벗어나면 인덱스 범위 오류를 막기 위해 바로 종료
        if (a[en] - a[st] < min) min = a[en] - a[st]; // 최솟값 갱신
        st++; // 현재 st에 대한 확인이 끝났으므로 st 증가
    }
    cout << min;
    return 0;
}
