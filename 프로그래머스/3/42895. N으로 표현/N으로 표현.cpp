#include <string>
#include <vector>
#include <set>

using namespace std;


int solution(int N, int number) {
    int answer = -1;
    
    vector<set<int>> nums(10); // N을 n번 썼을때 만들어지는 숫자들의 모음
    int concat = 0;
    for (int i = 1; i < 9; i++) {
        concat = concat * 10 + N;
        nums[i].insert(concat);
            
        for (int a = 1; a < i; a++) {
            int b = i - a;
            for (int num1: nums[a]) {      
                for (int num2: nums[b]) {
                    nums[i].insert(num1 + num2);
                    nums[i].insert(num1 - num2);
                    nums[i].insert(num1 * num2);
                    if (num2 != 0) nums[i].insert(num1 / num2);
                }
            }
        }
        if (nums[i].find(number) != nums[i].end()) return i;
    }
    
    return answer;
}