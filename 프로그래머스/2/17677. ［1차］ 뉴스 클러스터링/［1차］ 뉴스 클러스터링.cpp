#include <string>
#include <map>
#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    map<string, int> m1;
    map<string, int> m2;
    
    for (int i = 0; i < str1.size() - 1; i++) {
        if (isalpha(str1[i]) && isalpha(str1[i + 1])) {
            string s;
            s += tolower(str1[i]);
            s += tolower(str1[i + 1]);
            m1[s]++;
        }
    }    
    
    for (int i = 0; i < str2.size() - 1; i++) {
            if (isalpha(str2[i]) && isalpha(str2[i + 1])) {
            string s;
            s += tolower(str2[i]);
            s += tolower(str2[i + 1]);
            m2[s]++;
        }
    } 
    
    int uni = 0; int inter = 0;
    for (auto it : m1) {
        inter += min(it.second, m2[it.first]);
        uni += max(it.second, m2[it.first]);
        m2.erase(it.first);
    }
    for (auto it : m2) {
        inter += min(it.second, m1[it.first]);
        uni += max(it.second, m1[it.first]);
    }
        
    if (uni == 0) return 65536;
    answer = (double)inter / uni * 65536;
    
    return answer;
}