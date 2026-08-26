#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isused[10];
int answer = -1;

void dfs(int cur_fat, int cnt, vector<vector<int>>& dungeons) {
    if (cnt > answer) answer = cnt;
    
    if (cur_fat <= 0 || cnt == dungeons.size()) {
        return;
    }
    
    for  (int i = 0; i < dungeons.size(); i++) {
        if (!isused[i] && cur_fat >= dungeons[i][0]) {
            isused[i] = true;
            cur_fat -= dungeons[i][1];
            dfs(cur_fat, cnt + 1, dungeons);
            cur_fat += dungeons[i][1];
            isused[i] = false;
        }
    }
    
}

int solution(int k, vector<vector<int>> dungeons) {
    
    dfs(k, 0, dungeons);
    
    return answer;
}