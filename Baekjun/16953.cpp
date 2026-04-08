#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

long long a, b;

// int main() {
//     map<long long, int> m; // 현재 숫자, 연산 횟수

//     cin >> a >> b;
//     queue<pair<long long, int>> q;
//     q.push({a, 1});

//     while (!q.empty()) {
//         long long cur = q.front().first;
//         int count = q.front().second;
//         q.pop();

//         if (cur == b) {
//             cout << count;
//             return 0;
//         }


//         long long nxt1 = cur * 2;
//         if (nxt1 > b) continue;
//         q.push({nxt1, count + 1});

//         long long nxt2 = cur * 10 + 1;
//         if (nxt2 > b) continue;
//         q.push({nxt2, count + 1});
//     }

//     cout << -1;
//     return 0;
// }

int main() {

    cin >> a >> b;
    int count = 1;
    while (b > a) {
        if (b % 10 == 1) {
            b /= 10;
            count++;
        }
        else if (b % 2 == 0) {
            b /= 2;
            count++;
        }
        else {
            break; // 둘 다 안되면 반복문 종료
        }
    }   
    if (b == a) cout << count;
    else cout << -1;

    return 0;
}