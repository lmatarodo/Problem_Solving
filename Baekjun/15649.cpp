// http://boj.kr/f36567ec0c9f44b4b460b5b29683c27b
#include <iostream>
using namespace std;

int n,m;
int arr[10]; // 수열을 담는 배열
bool isused[10]; // 수열에서 특정 수가 쓰였는지를 true 혹은 false로 나타내는 배열

void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!isused[i]) {
            arr[k] = i;
            isused[i] = true;
            func(k + 1);
            isused[i] = false;
        }
    }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  func(0);
}