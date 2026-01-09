#include <iostream>

using namespace std;

int n, m;

int arr[8];

// void func(int k) {
//     if (m == k) {
//         for (int i = 0; i < m; i++) 
//             cout << arr[i] << ' ';
//         cout << '\n';
//         return;
//     }

//     for (int i = 1; i <= n; i++) {
//         if (!isused[i]  && (k == 0 || arr[k - 1] < i)) {
//             arr[k] = i;
//             isused[i] = true; 
//             func(k + 1);
//             isused[i] = false;
//         }
//     }
// } 위는 내가 구현한 버젼

void func(int k, int start) { // start: 이번 단계에서 뽑기를 시작할 지점
    if (m == k) {
        for (int i = 0; i < m; i++) 
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = start; i <= n; i++) { // 뽑기를 시작하는 지점부터 뽑음
        arr[k] = i;
        func(k + 1, i + 1); // 다음 뽑을 숫자는 현재 뽑는 숫자보다 더 큰 지점부터 탐색하도록 전달
    }
}

int main() {
    cin >> n >> m;
    func(0, 1);
    return 0;   
}