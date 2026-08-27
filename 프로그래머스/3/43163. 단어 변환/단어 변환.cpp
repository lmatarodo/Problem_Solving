#include <string>
#include <vector>
#include <queue>

using namespace std;

bool isDiffOne(string a, string b) {
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) cnt++;
        if (cnt >= 2) return false;
    }
    
    if (cnt == 1) return true;
    else return false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int n = words.size();
    vector<bool> isvisited(n, false);
    
    queue<pair<string, int>> q;
    q.push({begin, 0});
    
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        string curname = cur.first; int curdist = cur.second;
        
        if (curname == target) {
            answer = cur.second;
            return answer;
        }
        
        for (int i = 0; i < words.size(); i++) {
            if (!isvisited[i] && isDiffOne(words[i], curname)) {
                isvisited[i] = true;
                q.push({words[i], curdist + 1});
            }
        }
    }
    
    return answer;
}