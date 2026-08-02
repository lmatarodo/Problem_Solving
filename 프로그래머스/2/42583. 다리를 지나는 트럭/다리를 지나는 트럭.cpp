#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int> bridge;
    int bridge_weight = 0;
    for (int i = 0; i < bridge_length; i++) {
        bridge.push(0);
    }
    
    int idx = 0;
    while (idx < truck_weights.size()) {
        bridge_weight -= bridge.front();
        bridge.pop();
        
        if (bridge_weight + truck_weights[idx] <= weight) {
            bridge.push(truck_weights[idx]);
            bridge_weight += truck_weights[idx];
            idx++;
            
        }
        else {
            bridge.push(0);
        }
        answer++;
    }
    answer += bridge_length;
    
    return answer;
}