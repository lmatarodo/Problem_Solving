#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> u;
vector<int> two;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    int num;
    for (int i = 0; i < n; i++) {
        cin >> num; 
        u.push_back(num);
    }
    
    sort(u.begin(), u.end());

    for (int i = 0; i < u.size(); i++) 
        for (int j = i; j < u.size();j++) two.push_back(u[i] + u[j]);
    
    sort(two.begin(), two.end());    

    int max = 0;

    for (int i = 0; i < u.size(); i++) {
        for (int j = i; j < u.size(); j++) {
            if (binary_search(two.begin(), two.end(), (u[j] - u[i])) && max < u[j]) max = u[j];
        }
    }

    cout << max;
    return 0;
}
