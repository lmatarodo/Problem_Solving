#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int arr2[4] = {1, 3, 4, 5};
    int arr3[5] = {3, 1, 2, 4, 5};
    
    vector<int> students(4, 0);
    for (int i = 0; i < answers.size(); i++) {
        if ((i % 5) + 1 == answers[i]) {
            students[1]++;
        }
        
        if (i % 2 == 0) {
            if (answers[i] == 2) students[2]++;
        }
        
        else if (i % 2 == 1) {
            int idx = (i % 8) / 2;
            if (answers[i] == arr2[idx]) students[2]++;
        }
        
        int idx2 = (i % 10) / 2;
        if (answers[i] == arr3[idx2]) students[3]++;
    }
    
    int max_val = *max_element(students.begin(), students.end());
    for (int i = 1; i < 4; i++) {
        if (max_val == students[i]) answer.push_back(i);
    }
    return answer;
}