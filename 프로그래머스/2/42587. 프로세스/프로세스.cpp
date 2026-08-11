#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q; // 우선순위, 인덱스 번호
    priority_queue<int> pq;
    vector<int> turn(priorities.size());
    
    for (int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }
    
    int cnt = 0;
    while (!q.empty()) {
        auto cur = q.front();
        if (cur.first < pq.top()) {
            q.push(cur);
            q.pop();
        }
        else {
            turn[cur.second] = cnt;
            cnt++;
            q.pop(); pq.pop();
        }
    }
    
    answer = turn[location] + 1;
    return answer;
}