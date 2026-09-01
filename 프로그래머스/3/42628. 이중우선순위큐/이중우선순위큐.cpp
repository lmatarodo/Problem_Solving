#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<pair<int, int>> maxQ;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int ,int>>> minQ;
    bool deleted[1000002];
    
    int id = 0;
    
    for (int i = 0; i < operations.size(); i++) {
        char op = operations[i][0];
        
        if (op == 'I') {
            int num = stoi(operations[i].substr(2));
            
            maxQ.push({num, id});
            minQ.push({num, id});
            
            id++;
        }
        
        else if (op == 'D') {
            if (operations[i][2] == '1') {
                while (!maxQ.empty() && deleted[maxQ.top().second]) {
                    maxQ.pop();
                }
                
                if (!maxQ.empty()) {
                    deleted[maxQ.top().second] = true;
                    maxQ.pop();
                }
                
            }
            
            else if (operations[i][2] == '-') {
                while (!minQ.empty() && deleted[minQ.top().second]) {
                    minQ.pop();
                }
                
                if (!minQ.empty()) {
                    deleted[minQ.top().second] = true;
                    minQ.pop();
                }
            }
        }
    }
    
    while (!maxQ.empty() && deleted[maxQ.top().second]) 
        maxQ.pop();
    
    while (!minQ.empty() && deleted[minQ.top().second])
        minQ.pop();
    
    if (maxQ.empty() || minQ.empty()) {
        answer.push_back(0); answer.push_back(0);
    }
    else {
        answer.push_back(maxQ.top().first); answer.push_back(minQ.top().first);
    }
    
    return answer;
}