#include <iostream>
#include <algorithm>

using namespace std;

int n, s;
int a[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> a[i];
    int st = 0; int en = 0;
    int sum = 0;
    int ans = 0x7fffffff;
    
    while (true) {
        if (sum < s && en < n) {
            sum += a[en]; // 인덱스를 옮기기 전에 sum에 반영
            en++;
        }
        else if (sum >= s) {
            ans = min(ans, en - st);
            sum -= a[st]; // 인덱스를 옮기기 전에 sum에 반영
            st++;
        }
        else if (en == n) break; // 끝 조건에 도달하면 종료
    }

    if (ans == 0x7fffffff) cout << 0; // 만약 찾지 못했으면 0을 출력
    else cout << ans;

    return 0;
}
