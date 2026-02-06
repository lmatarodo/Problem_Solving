#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a[100002];

int binarySearch(int target){
    int st = 0; int en = n - 1;
    while (st <= en) {
        int mid = (st + en) / 2; // mid를 업데이트하는 과정이 반드시 필요
        if (a[mid] > target) en = mid - 1;
        else if (a[mid] < target) st = mid + 1;
        else if (a[mid] == target) return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    sort(a, a + n); // 이분탐색의 대상이 되는 배열은 꼭 정렬을 수행해주어야함.
    cin >> m;
    int target;
    while (m--) {
        cin >> target;
        cout << binarySearch(target) << '\n';
    }

    return 0;
}
