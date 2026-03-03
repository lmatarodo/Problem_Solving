#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int n = s.length();
    int answer = n;
    
    for (int i = 1; i <= n / 2; i++)  {
        string prev = s.substr(0, i);
        int len = 0;
        int cnt = 1;
        
        for (int j = i; j < n; j += i) {
            string cur = s.substr(j, i);
            if (prev == cur) cnt++;
            else {
                len += prev.length();
                if (cnt >= 2) len += to_string(cnt).length();
                cnt = 1;
                prev = cur;
            }
        }
        
        len += prev.length();
        if (cnt >= 2) len += to_string(cnt).length();
        answer = min(len, answer);
    }
    return answer;
}