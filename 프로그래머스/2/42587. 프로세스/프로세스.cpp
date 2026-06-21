#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> q; // 우선순위, 들어간 순서(원래 location과의 대조)
    priority_queue<int> pq;
    
    for (int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }
    
    int cnt = 0; // 몇번째로 실행되는지
    while (!q.empty()) {
        auto nxt = q.front(); q.pop();
        if (pq.top() > nxt.first) {
            q.push(nxt);
        }
        
        else {
            pq.pop();
            cnt++;
            if (nxt.second == location) {
                answer = cnt;
                break;
            }
        }
    }
    
    return answer;
}