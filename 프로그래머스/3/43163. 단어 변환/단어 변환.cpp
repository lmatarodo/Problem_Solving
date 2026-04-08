#include <string>
#include <vector>
#include <queue>

#define X first
#define Y second

using namespace std;

bool isDiffOne(string& a, string& b) {
    int diffCnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) diffCnt++;
    }
    if(diffCnt == 1) return true;
    else return false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int n = words.size();
    queue<pair<string, int>> q;
    vector<int> visited(n, -1);

    for (int i = 0; i < words.size(); i++) {
        if (isDiffOne(begin, words[i])) {
            q.push({words[i], i});
            if (words[i] == target) return 1;
            visited[i] = 1;
        }
    }
    
    while (!q.empty()) {
        
        auto cur = q.front(); q.pop();
        
        for (int i = 0; i < words.size(); i++) {
            if (visited[i] == -1 && isDiffOne(cur.X, words[i])) {
                q.push({words[i], i});
                visited[i] = visited[cur.Y] + 1;
                if (words[i] == target) {
                    answer = visited[i];
                    return answer;
                }
            }
        }
        
    }
    
    
    return 0;
}