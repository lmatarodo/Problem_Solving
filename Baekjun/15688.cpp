#include <iostream>

using namespace std;

int freq[2000002];

int main() {

    int n;
    int num;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        freq[num + 1000000]++;
    }

    for (int i = 0; i <= 2000000; i++) {
        if (freq[i] != 0) {
            for (int j = 0; j < freq[i]; j++) 
                cout << i - 1000000 << '\n';
        }
    }

    return 0;
}