#include <iostream>
#include <algorithm>

using namespace std;

int n, x;
int a[100002];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> x;

    sort(a, a + n);
    int left = 0; int right = n - 1;

    int cnt = 0;
    while (left < right) {
        int sum = a[left] + a[right];
        if (sum < x) left++;
        else if (sum > x) right--;
        else if (sum == x) {
            cnt++;
            left++;
            right--;
        }
    }    
    cout << cnt;

    return 0;
}

