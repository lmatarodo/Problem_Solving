#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int nums[10];
int ans[10];

void func(int k, int start) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            cout << ans[i] << " ";
        cout << "\n";
        return;
    }

    // 같은 자리에 같은 숫자를 또 쓰는 것을 방지하기 위해 last_used 변수를 사용했다!
    int last_used = -1;
    for (int i = start; i < n; i++) {

        if (nums[i] != last_used) {
            ans[k] = nums[i];
            last_used = nums[i];
            func(k + 1, i);
        }
    }
    
}

int main() {

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    sort(nums, nums + n);
    func(0, 0);

    return 0;
}