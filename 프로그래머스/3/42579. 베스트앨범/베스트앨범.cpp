#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, int> genrePlay; // 장르명, 총 재생횟수
    unordered_map<string, vector<pair<int, int>>> genreSong; // 장르명, 그 장르에 속한 각 노래의 조회수의 인덱스 번호
    for (int i = 0; i < genres.size(); i++) {
        genrePlay[genres[i]] += plays[i];
        genreSong[genres[i]].push_back({plays[i], i});
    }
    
    vector<pair<string, int>> v;
    for (auto& e: genrePlay)
        v.push_back({e.first, e.second});
    
    sort(v.begin(), v.end(), [] (auto& a, auto& b) {
        return a.second > b.second;
    });
    
    for (auto& e: v) {
        sort(genreSong[e.first].begin(), genreSong[e.first].end(), [](auto& a, auto& b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        });
        
        answer.push_back(genreSong[e.first][0].second);
        if (genreSong[e.first].size() >= 2) answer.push_back(genreSong[e.first][1].second);
    }
    
    
    
    return answer;
}