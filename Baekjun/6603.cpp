#include <iostream>

using namespace std;

int k;
int s[50];
bool visited[50];
int arr[6];

void func(int num, int start) {
    if (num == 6) {
        for (int i = 0; i < 6; i++) 
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = start; i < k; i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr[num] = s[i];
            func(num + 1, i + 1);
            visited[i] = false;
        }
    }
}

int main() {

    while (true) {
        cin >> k;
        if (k == 0) break;
        for (int i = 0; i < k; i++) {
            cin >> s[i];
        }
        func(0, 0);
        cout << "\n";

    }
    return 0;
}