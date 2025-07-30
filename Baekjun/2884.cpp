#include <iostream>

using namespace std;

int main() {
    int H, M;
    cin >> H >> M;
    
    if (M >= 45) {
        cout << H  << " " << M - 45 << "\n";
    }
    
    else {
        if (H == 0) {
            cout << "23 " << M + 15 << "\n";
        }
        else {
            cout << H - 1 << " " << M + 15 << "\n";
        }
    }

    return 0;
}