#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int A, B, C;

    while (true) {
        cin >> A >> B >> C;
        if ( A == 0 && B == 0 && C == 0) {
            break;
        }
        
        if (A > B && A > C) {
            if (pow(A, 2) == pow(B, 2) + pow(C, 2)) {
                cout << "right" << "\n";
            }
            else {
                cout << "wrong" << "\n";
            }            
        }

        else if (B > A && B > C) {
            if (pow(B, 2) == pow(A, 2) + pow(C, 2)) {
                cout << "right" << "\n";
            }
            else {
                cout << "wrong" << "\n";
            }   
        }

        else if (C > A && C > B) {
            if (pow(C, 2) == pow(A, 2) + pow(B, 2)) {
                cout << "right" << "\n";
            }
            else {
                cout << "wrong" << "\n";
            }   
        }
    }
    return 0;
}