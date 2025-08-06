#include <iostream>
#include <string>

using namespace std;

int main() {

    int A, B, C;
    int count[10] = {0,};

    cin >> A >> B >> C;

    int mult = A * B * C;
    string multstr = to_string(mult);

    for (int i = 0; i < multstr.length(); i++) {
        count[multstr[i] - '0'] += 1;
    }

    for (int i = 0; i < 10; i++) {
        cout << count[i] << "\n";
    }
    return 0;
}