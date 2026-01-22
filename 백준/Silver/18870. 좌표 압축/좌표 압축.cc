#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int x[1000002];
int temp1[1000002]; // x 배열의 원래 값들을 미리 담아놓음
vector<int> uni; // x 배열을 정렬하고 중복을 제거한 후의 배열

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> x[i];
    
    for (int i = 0; i < n; i++) 
        temp1[i] = x[i];
    
    sort(x, x + n);

    uni.push_back(x[0]);
    for (int i = 1; i < n; i++) 
        if (x[i - 1] != x[i]) uni.push_back(x[i]);
    
    for (int i = 0; i < n; i++) {
        cout << lower_bound(uni.begin(), uni.end(), temp1[i]) - uni.begin() << " ";
    }
    return 0;
}
