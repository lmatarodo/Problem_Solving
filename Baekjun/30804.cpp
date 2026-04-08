#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[10];
int s[200002];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int left = 0; 
    int max_len = 0;
    int type_cnt = 0;

    for (int right = 0; right < n; right++) {
        if (arr[s[right]] == 0) type_cnt++;
        arr[s[right]]++;

        while (type_cnt > 2) {
            arr[s[left]]--;
            if (arr[s[left]] == 0) type_cnt--;
            left++;
        }

        max_len = max(max_len, right - left + 1);
    }
    cout << max_len;

    return 0;
}