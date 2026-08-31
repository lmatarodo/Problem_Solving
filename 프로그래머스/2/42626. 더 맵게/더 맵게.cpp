#include <string>
#include <vector>
#include <queue>


using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> min_pq;
    for (int i = 0; i < scoville.size(); i++) {
        min_pq.push(scoville[i]);
    }
    
    while (min_pq.top() < K && min_pq.size() >= 2) {
        int newSco = min_pq.top(); min_pq.pop();
        newSco += 2 * min_pq.top(); min_pq.pop();
        
        min_pq.push(newSco);
        answer++;
    }
    
    if (min_pq.top() < K) {
        answer = -1;
        return answer;
    }
    
    return answer;
}