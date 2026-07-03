#include <string>
#include <vector>
#include <queue>

using namespace std;

bool isDiffone(string a, string b) {
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) cnt++;
        if (cnt > 2) return false; // 조기 종료
    }
    
    if (cnt == 1) return true;
    else return false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int n = words.size();
    
    vector<int> dist(n + 1, -1);
    queue<pair<string, int>> q; // 두번째 int는 words에 있는 인덱스 번호
    q.push({begin, -1});
    
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        
        if (cur.first == target) answer = dist[cur.second] + 1;
        
        for (int i = 0; i < words.size(); i++) {
            if (dist[i] == -1 && isDiffone(cur.first, words[i])) {
                q.push({words[i], i});
                if (cur.second == -1) dist[i]++;
                else dist[i] = dist[cur.second] + 1;
            }
            
        }
    }

    
    return answer;
}