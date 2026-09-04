#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string recurseAlgo(string w) {
    if (w.empty()) return "";
        
    int lcnt = 0, rcnt = 0;
    
    string u;
    bool isOk = true; // u가 올바른 문자열인지 여부
    int idx = 0;
    for (int i = 0; i < w.size(); i++) {
        
        if (w[i] == '(') lcnt++; if (w[i] == ')') rcnt++;
        if (lcnt - rcnt < 0) isOk = false;

        u += w[i];
        if (lcnt == rcnt) {
            idx = i;
            break;
        }
    }
    
    string v = w.substr(idx + 1);
    
    if (isOk) {
        v = recurseAlgo(v);
        return u + v;
    }
    
    else if (!isOk){
        string str = "(";
        str += recurseAlgo(v);
        str += ")";
        u.erase(0, 1); u.pop_back();
        
        for (char &c: u) {
            if (c == ')') c = '(';
            else c = ')';
        }
        str += u;
        return str;
    }
}

string solution(string p) {
    string answer = "";
        
    answer = recurseAlgo(p);
    
    return answer;
}