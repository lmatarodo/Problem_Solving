#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(string cur, vector<string>& answer, vector<bool>& isused, vector<vector<string>>& tickets) {
    if (answer.size() == tickets.size() + 1) {
        return true;
    }
    
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == cur && !isused[i]) {
            isused[i] = true;
            answer.push_back(tickets[i][1]);
            if (dfs(tickets[i][1], answer, isused, tickets)) return true;
            isused[i] = false;
            answer.pop_back();
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    int n = tickets.size();
    vector<bool> isused(n, false);
    
    sort(tickets.begin(), tickets.end());
    answer.push_back("ICN");
    dfs("ICN", answer, isused, tickets);
    return answer;
}