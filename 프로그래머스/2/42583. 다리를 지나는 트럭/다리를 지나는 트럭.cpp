#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int n = truck_weights.size();
    queue<int> q; // 다리의 역할을 하는 큐
    
    for (int i = 0; i < bridge_length; i++)
        q.push(0);
    
    int sum = 0;
    int idx = 0;
    
    while (idx < n) {
        sum -= q.front();
        q.pop();
        if (sum + truck_weights[idx] <= weight) {
            sum += truck_weights[idx];
            q.push(truck_weights[idx]);
            idx++;
        } 
        else {
            q.push(0);
        }
        

        answer++;
        
        
    }
    
    answer += bridge_length;
    return answer;
}