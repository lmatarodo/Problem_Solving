#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

// int main() {
//     cin >> n;
//     vector<int> v;
//     int num;

//     for (int i = 0; i < n; i++) {
//         cin >> num;
//         if (v.empty()) v.push_back(num);
//         if (!v.empty() && v.back() < num) v.push_back(num);
//         if (!v.empty() && v.back() >= num) {
//             auto it = lower_bound(v.begin(), v.end(), num);
//             *it = num;
//         }
//     }

//     cout << v.size();

//     return 0;
// }

int dp[1002];
int arr[1002];

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int result = *max_element(dp, dp + n);
    cout << result;

    return 0;
}