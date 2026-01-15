#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& a, const string& b) {

    if (a.length() != b.length())
        return a.length() < b.length();

    else if (a.length() == b.length()) {
        int anum = 0, bnum = 0;
        for (int i = 0; i < a.length(); i++) {
            if (isdigit(a[i])) anum += a[i] - '0';
        }
        for (int i = 0; i < b.length(); i++) {
            if (isdigit(b[i])) bnum += b[i] - '0';
        }        
        if (anum != bnum)
            return anum < bnum;
    }
    return a < b;

}   

int main() {
    int n;
    cin >> n;
    string s;
    vector<string> v;

    for (int i = 0; i < n; i++) {
        cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end(), cmp);
    
    for (int i = 0; i < n; i++) {
        cout << v[i] << '\n';
    }
    return 0;
}