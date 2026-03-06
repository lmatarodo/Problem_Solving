#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int n, m;
int arr[8];
int ipt[8];
bool isused[8];
int globAns;
set<int> s;

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void func(int k) {
    if (k == m) {
        int num = 0;
        for (int i = 0; i < m; i++)
            num = num * 10 + arr[i];
        cout << num << "\n";
        s.insert(num);
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (!isused[i]) {
            arr[k] = ipt[i];
            isused[i] = 1;
            func(k + 1);
            isused[i] = 0;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    n = numbers.size();
    for (int i = 0; i < n; i++)
        ipt[i] = numbers[i] - '0';
    
    for (int i = 1; i <= n; i++){
        m = i;
        func(0);
    }
    
    for (auto it :s) {
        if (isPrime(it)) answer++;
    }
    
    return answer;
}