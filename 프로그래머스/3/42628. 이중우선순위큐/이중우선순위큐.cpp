#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> mq;
    
    for (int i = 0; i < operations.size(); i++) {
        char op = operations[i][0];
        
        if (op == 'I') {
            int num = stoi(operations[i].substr(2));
            mq.insert(num);
        }
        
        else if (op == 'D') {
            if (!mq.empty() && operations[i][2] == '1') { // 최댓값 하나 삭제
                mq.erase(prev(mq.end()));
            }
            
            else if (!mq.empty() && operations[i][2] == '-') { // 최솟값 하나 삭제
                mq.erase(mq.begin());
            }
        }
    }
    
    if (mq.empty()) {
        answer.push_back(0); answer.push_back(0);
    }
    else {
        answer.push_back(*mq.rbegin());
        answer.push_back(*mq.begin());
    }
    
    
    return answer;
}