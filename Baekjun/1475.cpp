#include <iostream>

using namespace std;

string n;
int counts[10];

int main() {
    cin >> n;

    for (int i = 0; i < n.size(); i++) {
        counts[n[i] - '0']++;
    }

    int except = (counts[6] + counts[9] + 1) / 2;
    int otherMax = 0;
    for (int i = 0; i < 10; i++) {
        if (i == 6 || i == 9) continue;
        otherMax = max(otherMax, counts[i]);
    }
    
    cout << max(otherMax, except);

    return 0;
}