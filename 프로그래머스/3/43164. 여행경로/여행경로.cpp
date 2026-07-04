#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(string cur, vector<vector<string>>& tickets, vector<bool>& visited ,vector<string>& answer) {
    if (answer.size() == tickets.size() + 1) return true;
    
    for (int i = 0; i < tickets.size(); i++) {
        if (!visited[i] && tickets[i][0] == cur) {
            visited[i] = true;
            answer.push_back(tickets[i][1]);
            if (dfs(tickets[i][1], tickets, visited, answer))
                return true;
            visited[i] = false;
            answer.pop_back();
        }
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    int n = tickets.size();
    vector<bool> visited(n + 1, false);
    
    sort(tickets.begin(), tickets.end());
    
    answer.push_back("ICN");
    dfs(answer[0], tickets, visited, answer);
    return answer;
}