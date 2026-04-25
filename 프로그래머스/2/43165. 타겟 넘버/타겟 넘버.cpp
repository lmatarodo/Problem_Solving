#include <string>
#include <vector>

using namespace std;

int t;
int answer = 0;

void dfs(int depth, int sum, vector<int>& numbers) {
    if (depth == numbers.size()) {
        if (sum == t) {
            answer++;
        }
        return;
    }
    
    dfs(depth + 1, sum + numbers[depth], numbers);
    dfs(depth + 1, sum - numbers[depth], numbers);
}

int solution(vector<int> numbers, int target) {
    t = target;
    dfs(0, 0, numbers);
    return answer;
}