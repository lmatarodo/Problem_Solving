#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    queue<pair<int, int>> q; // 서버가 만료되는 시간, 서버가 증설된 갯수
    int curr_server = 0;
    
    for (int t = 0; t < 24; t++) {
        
        while (!q.empty() && q.front().first == t) {
            curr_server -= q.front().second;
            q.pop();
        }
        
        int need_server = players[t] / m;
        
        if (need_server > curr_server) {
            int to_add = need_server - curr_server;
            curr_server += to_add;
            answer += to_add;
            q.push({t + k, to_add});
        }
    }
    
    return answer;
}