#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int n, m;
int ipt[10];
int arr[10]; // 수열을 담아놓는 배열
bool isused[10]; // ipt의 특정 원소가 사용되었는지를 나타냄

void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int last_val = 0; // 놓친 점: 재귀 함수 각각 호출 시마다 고유의 last_val 값을 갖게 해주려면 last_val을 지역변수로 선언해주어야함. 이전 값이 어떤 값이었는지를 저장하여 중복된 값이 나오지 않게 해줌
    for (int i = 0; i < n; i++) {
        if (!isused[i] && ipt[i] != last_val) { // set의 특정 원소가 아직 사용되지 않았다면,
            arr[k] = ipt[i];
            last_val = ipt[i]; // 이전 값이 어떤 값이었는지를 저장하고
            isused[i] = true;
            func(k + 1); // 다음 재귀 수행
            isused[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> ipt[i];
    }
    sort(ipt, ipt + n);

    func(0);
    return 0;
}