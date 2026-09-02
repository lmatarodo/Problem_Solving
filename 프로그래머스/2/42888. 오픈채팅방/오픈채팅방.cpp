#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;    
    vector<pair<string,string>> subrecord; // id, 어떤 행동을  했는지
    
    map<string, string> chat; // id, 닉네임
    
    for (string r: record) {
        stringstream ss(r);
        string order, uid, nickname;
        
        ss >> order >> uid;
        
        if (order == "Enter" || order == "Change") {
            ss >> nickname;
            chat[uid] = nickname;
            if (order == "Enter") {
                subrecord.push_back({uid, "in"});
            }
        }
        
        else if (order == "Leave") {
            subrecord.push_back({uid, "out"});
        }
    }
    
    for (auto sr: subrecord) {
        string ipt = chat[sr.first] + "님이 ";
        if (sr.second == "in") {
            ipt += "들어왔습니다.";
        }
        else if (sr.second == "out") {
            ipt += "나갔습니다.";
        }
        
        answer.push_back(ipt);
    }
    
    return answer;
}