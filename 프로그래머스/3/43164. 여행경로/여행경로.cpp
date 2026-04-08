#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
bool visited[10002]; // 티켓 별로 방문했는지 인덱스를 의미함
vector<string> answer;

// return true를 안하면 경로를 찾아도 return을 통해 돌아오게 됨
// bool형을 반환하게 하여 
bool dfs(string cur, int depth, vector<vector<string>>& tickets) {
    if (depth == n) { // 모든 공항을 돔
        return true; // 참을 반환하게 해야하고 종료시킴
    }
    
    for (int i = 0; i < tickets.size(); i++) {
        if (!visited[i] && tickets[i][0] == cur) {
            visited[i] = true;
            answer.push_back(tickets[i][1]);
            
            if (dfs(tickets[i][1], depth + 1, tickets)) return true; // 재귀 호출 결과가 true면 그대로 종료
            
            answer.pop_back();
            visited[i] = false;
        }
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    
    sort(tickets.begin(), tickets.end());
    n = tickets.size();
    answer.push_back("ICN");
    dfs("ICN", 0, tickets);
    
    return answer;
}