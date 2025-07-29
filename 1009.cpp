#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    int T;
    int a, b;
    int comNum = 1;
    
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        comNum = 1;
        cin >> a >> b;
        for (int j = 0; j < b; j++) {
            comNum *= a;
            comNum %= 10;
        }

        if (!comNum % 10) {
            cout << 10 << "\n";
        }
        else {
            cout << comNum << "\n";
        }    
    }

    return 0;
}