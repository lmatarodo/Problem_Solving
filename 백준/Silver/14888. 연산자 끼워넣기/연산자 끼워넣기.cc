#include <iostream>

using namespace std;

int n;
int arr[12];
int isPos[4];
int maxV = -1e9;
int minV = 1e9;

void func(int depth, int sum) {
    if (depth == n) {
        if (sum > maxV) maxV = sum;
        if (sum < minV) minV = sum;
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (isPos[i] > 0) {
            isPos[i]--;
            if (i == 0) func(depth + 1, sum + arr[depth]);
            else if (i == 1) func(depth + 1, sum - arr[depth]);
            else if (i == 2) func(depth + 1, sum * arr[depth]);
            else if (i == 3) func(depth + 1, sum / arr[depth]);
            isPos[i]++;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    for (int i = 0; i < 4; i++)
        cin >> isPos[i];
    
    func(1, arr[0]);
    cout << maxV << "\n" << minV;
}