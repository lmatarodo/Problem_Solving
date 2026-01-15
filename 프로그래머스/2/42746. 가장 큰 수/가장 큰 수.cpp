#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& a, const string &b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strnum;
    for (auto n : numbers)
        strnum.push_back(to_string(n));
    
    sort(strnum.begin(), strnum.end(), cmp);
    
    string result;
    if (strnum[0] == "0") return "0";
    for (auto s: strnum)
        result += s;
    
    answer = result;
    
    return answer;
}