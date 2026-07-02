#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weigth, vector<int> truck_weights) {
    int answer = 0;
    queue<int> bridge;
    
    for (int i = 0; i < bridge_length; i++) 
        bridge.push(0);
    
    int idx = 0;
    int curWeigth = 0;
    
    while (!bridge.empty()) {
        answer++;
        curWeigth -= bridge.front();
        bridge.pop();
        
        if (idx < truck_weights.size()) {
            if (curWeigth + truck_weights[idx] <= weigth) {
                curWeigth += truck_weights[idx];
                bridge.push(truck_weights[idx]);
                idx++;
            }
            
            else {
                bridge.push(0);
            }
        }
        
    }
    
    return answer;
}