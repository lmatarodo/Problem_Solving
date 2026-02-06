#include <iostream>

using namespace std;

int n;
int num;

int isPrime(int x) {
    if (x == 1) return 0;
    for (int i = 2; i * i <= x; i++) 
        if (x % i == 0) return 0; 
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;

    int ans = 0;
    while (n--) {
        cin >> num;
        ans += isPrime(num);
    }

    cout << ans;

    return 0;
}
