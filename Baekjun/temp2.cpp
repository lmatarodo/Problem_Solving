#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int num;
    cin >> n;
    vector<int> origin;
    vector<int> sorted;

    for (int i = 0; i < n; i++) {
        cin >> num;
        origin.push_back(num);
        sorted.push_back(num);
    }
    
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(sorted.begin(), sorted.end(), origin[i]) - sorted.begin();
        cout << idx << " ";
    }

    return 0;
}