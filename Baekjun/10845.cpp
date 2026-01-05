#include <iostream>
#include <queue>

using namespace std;
const int MX = 1000005;
int dat[MX];
int head, tail;

void push(int x){
    dat[tail++] = x;
}

void pop() {
    head++;
}

int size() {
    return tail - head;
}

int front() {
    return dat[head];
}

int back() {
    return dat[tail - 1];
}

int main() {
    int N;
    cin >> N;

    while (N--){
        string s;
        cin >> s;
        if (s == "push"){
            int plus;
            cin >> plus;
            push(plus);
        }

        else if (s == "pop") {
            if (head == tail) 
                cout << "-1\n";
            else {
                cout << front() << "\n";
                pop();
            }
        }

        else if (s == "size") {
            cout << size() << "\n";
        }

        else if (s == "empty") {
            if (tail == head) cout << "1\n";
            else cout << "0\n";
        }

        else if (s == "front") {
            if (tail == head) cout << "-1\n";
            else cout << front() << "\n";
        }

        else if (s == "back") {
            if (tail == head) cout << "-1\n";
            else cout << back() << "\n";
        }
    }

    return 0;
}