#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> nums;
bool isused[10];

void dfs(string cur, string& numbers) {
    if (!cur.empty()) nums.insert(stoi(cur));
    
    if (cur.size() == numbers.size()) return;
    
    for (int i = 0; i < numbers.size(); i++) {
        if (!isused[i]) {
            isused[i] = true;
            cur.push_back(numbers[i]);
            dfs(cur, numbers);
            isused[i] = false;
            cur.pop_back();
        }
    }
}

bool isPrime(int num) {
    if (num < 2) return false;
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    
    return true;
}

int solution(string numbers) {
    int answer = 0;
    
    dfs("", numbers);
    
    for (int num: nums) {
        if (isPrime(num)) answer++;
    }
    
    return answer;
}