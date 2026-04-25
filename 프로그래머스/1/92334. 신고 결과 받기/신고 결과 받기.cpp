#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, set<string>> m; //각 유저가 신고한 유저의 정보
    map<string, int> m2; // 누가 몇번 신고 당했는지
    
    for (string r: report) {
        stringstream ss(r);
        string from, to;
        ss >> from >> to;
        
        if (m[from].find(to) == m[from].end()) {
            m[from].insert(to);
            m2[to]++;
        }
    }
    
    for (string id: id_list) {
        int cnt = 0;
        for (string who: m[id]) {
            if (m2[who] >= k) {
                cnt++;
            }
        }
        answer.push_back(cnt);
    }
    
    return answer;
}