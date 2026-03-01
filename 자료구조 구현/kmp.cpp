#include <iostream>

using namespace std;

bool find(string& A, string& B) { // A가 B보다 길다고 가정
    for (int st = 0; st <= (int)(A.size() - B.size()); st++) {
        bool match = true;
        for (int i = 0; i < (int)B.size(); i++) {
            if (A[st + i] != B[i]) {
                match = false;
                break;
            }
            if (match) return true;
        }
    }
    return false;
}

vector<int> failure(string& s) {
    vector<int> f(s.size());
    int j = 0;
    for (int i = 1; i < s.size(); i++) {
        while (j > 0 && s[i] != s[j]) j = f[j - 1];
        if (s[i] == s[j]) f[i] = ++j;
    }
    return f;
}