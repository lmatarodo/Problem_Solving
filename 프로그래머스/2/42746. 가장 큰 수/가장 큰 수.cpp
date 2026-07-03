#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string& a, string& b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> nums;
    for (int num: numbers) {
        nums.push_back(to_string(num));
    }
    
    sort(nums.begin(), nums.end(), cmp);
    
    for (string num: nums) {
        answer += num;
    }
    if (answer[0] == '0') return "0";
    return answer;
}