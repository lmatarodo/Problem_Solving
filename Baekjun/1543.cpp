#include <iostream>

using namespace std;

int main() {
    string docs;
    string word;
    getline(cin, docs);
    getline(cin, word);

    int ans = 0;
    int pos = docs.find(word);

    while (pos != -1) {
        pos = docs.find(word, pos + word.size());
        ans++;
    }

    cout << ans;

    return 0;
}