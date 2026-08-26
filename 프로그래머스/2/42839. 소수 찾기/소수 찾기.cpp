#include <string>
#include <vector>
#include <string>
#include <set>

using namespace std;

bool isused[10];
set<int> s;

bool isPrime(int num) {
    if (num < 2) return false;
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void dfs(string curnum, string numbers) {
    
    if (curnum != "" && isPrime(stoi(curnum))) {
        s.insert(stoi(curnum));
    }
    
    if (curnum.size() == numbers.size()) {
        return;
    }
    
    for (int i = 0; i < numbers.size(); i++) {
        if (!isused[i]) {
            isused[i] = true;
            curnum += numbers[i];
            dfs(curnum, numbers);
            isused[i] = false;
            curnum.pop_back();
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    
    dfs("", numbers);
    
    answer = s.size();
    return answer;
}