#include <iostream>
//#include <deque>

using namespace std;

const int MX = 1000005;
int dat[2*MX + 1];
int head = MX, tail = MX; 

void push_front(int x) {
    dat[--head] = x;
}

void push_back(int x) {
    dat[tail++] = x;
}

void pop_front() {
    if (head < tail)
        head++;
}

void pop_back() {
    if (head < tail)
        tail--;
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

    while (N--) {
        string s;
        cin >> s;

        if (s == "push_front") {
            int plus;
            cin >> plus;
            push_front(plus);
        }

        else if (s == "push_back") {
            int plus;
            cin >> plus;
            push_back(plus);
        }

        else if (s == "pop_front") {
            if (head == tail)
                cout << "-1\n";
            else {
                cout << front() << "\n";
                pop_front();
            }
        }

        else if (s == "pop_back") {
            if (head == tail)
                cout << "-1\n";
            else {
                cout << back() << "\n";
                pop_back();
            }
        }

        else if (s == "size") {
            cout << tail - head << "\n";
        }

        else if (s == "empty"){
            if (head == tail)
                cout << "1\n";
            else 
                cout << "0\n";
        }

        else if (s == "front") {
            if (head == tail)
                cout << "-1\n";
            else 
                cout << front() << "\n";
        }

        else if (s == "back") {
            if (head == tail)
                cout << "-1\n";
            else 
                cout << back() << "\n";
        }

    }

    return 0;
}