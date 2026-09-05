#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int maxDiff = 0;

void dfs(int idx, int remain, vector<int>& info, vector<int>& cur, vector<int>& answer) { 
    // idx: 현재 보고 있는 점수 구간
    // remain: 라이언에게 남은 화살 갯수
    // cur: 현재까지 라이언이 배치한 화살
    // answer: 현재까지 찾은 최적 배치
    
    if (idx == 11 || remain == 0) {
        if (remain > 0) cur[10] += remain;

        
        int ryan = 0, apeach = 0;
        for (int i = 0; i < 11; i++) {
            if (cur[i] == 0 && info[i] == 0) continue; 
            int score = 10 - i;
            if (cur[i] > info[i]) ryan += score;
            else apeach += score;
        }
        int diff = ryan - apeach;
        
        if (diff > maxDiff) {
            maxDiff = diff;
            answer = cur;
        }
        else if (diff == maxDiff && diff > 0) {
            for (int i = 10; i >= 0; i--) {
                if (answer[i] < cur[i]) {
                    answer = cur;
                    break;
                }
                else if (answer[i] > cur[i])
                    break;
                
            }
        }
        if (remain > 0) cur[10] -= remain;
        
        return;
    }
    
    if (remain >= info[idx] + 1) {
        cur[idx] = info[idx] + 1;
        dfs(idx + 1, remain - info[idx] - 1, info, cur, answer);
        cur[idx] = 0;
    }
    
    dfs(idx + 1, remain, info, cur, answer);
    
    
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer(11, 0);
    vector<int> cur(11, 0);
    dfs(0, n, info, cur, answer);
    if (maxDiff == 0) return {-1};
    
    return answer;
}