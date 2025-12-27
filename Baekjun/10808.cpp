#include <iostream>

using namespace std;



int freq[26];
int main() {
    const int MX = 1000005;
    int dat[MX], prev[MX], next[MX];
    int unused  = 1;

    fill(prev, prev+MX, -1);
    fill(next, next+MX, -1);


    string s;
    cin >> s;
    for (auto c : s) {
        freq[c-'a']++;
    }
    for (int i =0 ; i < 26; i++) {
        cout << freq[i] << ' ';
    }
    return 0;
}

int func2(int arr[], int N) {
    int check[101] = {};
    for (int i = 0; i < N; i++) {
        check[arr[i]] = 1;
        if (check[100-arr[i]] == 1)
            return 1;
    }
    return 0;
}