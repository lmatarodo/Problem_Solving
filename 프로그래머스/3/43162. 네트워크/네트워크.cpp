#include <string>
#include <vector>

using namespace std;

bool isvisited[202];

void dfs(int curnode, vector<vector<int>>& computers) {
    for (int i = 0; i < computers[curnode].size(); i++) {
        if (!isvisited[i] && computers[curnode][i] == 1) {
            isvisited[i] = true;
            dfs(i, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i = 0; i < computers.size(); i++) {
        if (!isvisited[i]) {
            answer++;
            dfs(i, computers);
        }
    }
    
    return answer;
}