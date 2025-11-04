#include <iostream>

using namespace std;

int T, N, M;

int main() {
    int sum = 1;
    cin >> T;
    
//    for (int i = 0; i < T; i++) {
//        
//    }
    
    for (int i = 29; i > 16; i--) {
        sum *= i;
    }
    
    cout << sum << "\n";
    
    return 0;
}
 
