#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> primefac(int num) {
    vector<pair<int, int>> v;
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            v.push_back({num / i, i});
        }
    }
    return v;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int totalArea = brown + yellow;
    
    vector<pair<int, int>> mod = primefac(yellow);
    for (int i = 0; i < mod.size(); i++) {
        if ((mod[i].first + 2) * (mod[i].second + 2) == totalArea) {
            answer.push_back(mod[i].first + 2);
            answer.push_back(mod[i].second + 2);
        }
    }
        
    return answer;
}