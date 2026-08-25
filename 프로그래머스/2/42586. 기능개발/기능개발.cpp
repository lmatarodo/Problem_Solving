#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int n = progresses.size();
    vector<int> complete(n, 0);
    
    for (int i = 0; i < n; i++) {
        complete[i] = ceil((double)(100 - progresses[i]) / speeds[i]);
    }
    
    int max_idx = 0;
    int cur_max = complete[0];
    
    for (int i = 1; i < n; i++) {
        if (cur_max < complete[i]) {
            answer.push_back(i - max_idx);
            max_idx = i;
            cur_max = complete[i];
        }
    }
    answer.push_back(n - max_idx);
    
    return answer;
}