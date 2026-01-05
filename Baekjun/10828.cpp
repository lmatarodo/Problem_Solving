#include <iostream>

using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x) {
    dat[++pos] = x;
}

void pop() {
    if (pos == 0){
        cout << "-1\n";
    }
    else {
        cout << dat[pos] << "\n";
        pos--;
    }
}

void size(){
    cout << pos << "\n"; 
}

void empty(){
    if (pos == 0) {
        cout << "1\n";
    }
    else {
        cout << "0\n";
    }
}

void top() {
    if (pos == 0){
        cout << "-1\n";
    }
    else {
        cout << dat[pos] << "\n";
    }
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        string s;
        cin >> s;
        if (s == "push") {
            int plus;
            cin >> plus;
            push(plus);
        }

        else if (s == "pop")
            pop();
        else if (s == "size")
            size();
        else if (s == "empty")
            empty();
        else if (s == "top")
            top();
    }

    return 0;
}