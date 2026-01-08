#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

bool isDiffOne(string origin, string target) {
    int diff = 0;
    for (int i = 0; i < origin.length(); i++) {
        if (origin[i] != target[i]) diff++;
    }
    if (diff == 1) return true;
    else return false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<int> dist(words.size(), -1);
    queue<pair<string, int>> q;
    q.push({begin, -1});
    
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        
        for (int i = 0; i < words.size(); i++) {
            if (isDiffOne(curr.first, words[i]) && dist[i] < 0) {
                dist[i] = dist[curr.second] + 1;
                q.push({words[i], i});
            }
            if (words[i] == target) answer = dist[i];
        }
    }
    
    
    return answer;
}