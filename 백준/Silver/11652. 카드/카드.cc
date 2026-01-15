#include <iostream>
#include <algorithm>

using namespace std;

long long arr[100002];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int cnt = 0; // 현재 보고 있는 값이 몇번 등장했는지
    int maxCnt = 0; // 현재까지 값 중에 가장 최대로 등장한 숫자의 횟수
    long long maxVal = -(111 << 62) - 1; // 가장 많이 등장한 숫자

    int currNum = arr[0];
    maxVal = arr[0];

    for (int i = 0; i < n; i++) {
        if (currNum != arr[i]) {
            currNum = arr[i];
            if (cnt > maxCnt) { // 최댓값 갱신
                maxCnt = cnt;
                maxVal = arr[i - 1];
            }
            cnt = 0;
        }
        cnt++;
    }
    if (cnt > maxCnt) maxVal = arr[n-1];

    cout << maxVal;


    return 0;
}