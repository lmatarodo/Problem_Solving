#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> genrePlay; // 장르명과 그 장르의 총 조회수
    unordered_map<string, vector<pair<int, int>>> genreSong; // 노래가 속한 장르명과 그 노래의 조회수, 인덱스 번호
    
    for (int i = 0; i < genres.size(); i++) {
        genrePlay[genres[i]] += plays[i];
        genreSong[genres[i]].push_back({plays[i], i});
    }
    vector<pair<string, int>> order(genrePlay.begin(), genrePlay.end());
    sort(order.begin(), order.end(), [] (const auto & a, const auto& b) {
        return a.second > b.second;
    });
        
        
    for (auto& e: order) {
        sort(genreSong[e.first].begin(), genreSong[e.first].end(), [] (const auto& a, const auto& b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        });
            
        answer.push_back(genreSong[e.first][0].second);
        if (genreSong[e.first].size() >= 2) answer.push_back(genreSong[e.first][1].second);
    }
    
    return answer;
}