#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int arr[9];
int ipt[9]; // 수열의 조합으로 쓰일 숫자들을 담아놓음

void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) 
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }    

    for (int i = 0; i < n; i++) {
        arr[k] = ipt[i];
        func(k + 1);
    }

}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> ipt[i];
    sort(ipt, ipt + n);    
    func(0);
    return 0;
}