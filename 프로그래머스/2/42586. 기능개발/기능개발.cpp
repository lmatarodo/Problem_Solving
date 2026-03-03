#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> complete;
    
    for (int i = 0; i < int(progresses.size()); i++) 
        complete.push_back(ceil(double(100 - progresses[i]) / speeds[i]));
    
    
    for (int i = 0; i < int(complete.size()); i++) {
        int j = i + 1;
        int cnt = 1;
        while (j < (int)complete.size() && complete[i] >= complete[j]) {
            j++;
            cnt++;
        }
        i = j - 1;
        answer.push_back(cnt);
    }
    
    return answer;
}