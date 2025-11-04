#include <iostream>
#include <cmath>

using namespace std;

int T, N, M;

long long int combination(int &n, int &m) {
    
    if (n == m)
        return 1;
    if (m == 1)
        return n;
    
    long double result = 1;
    int j = 0;
    
    for (int i = n; i > 0; --i) {
        int d1 = m <= 0 ? 1 : m;
        int d2 = (n - m - j) <= 0 ? 1 : (n - m - j);
        
        int d = d1 * d2;
        
        result *= i;
        result /= d;
        
        n--;
        m--;
        j++;
    }
    return round(result);
}

int main() {
    cin >> T;
    
    while (T--) {
        cin >> N >> M;
        cout << combination(M,N) << "\n";
    }
    return 0;
}
 
