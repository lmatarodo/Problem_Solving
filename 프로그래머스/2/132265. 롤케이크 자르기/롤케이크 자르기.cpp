#include <string>
#include <vector>
#include <set>

using namespace std;

int forwardgo[1000002]; // 앞으로 가면서 현재까지 총 몇개의 종류가 등장했는지를 저정
int backward[1000002]; // 뒤로 가

int solution(vector<int> topping) {
    int answer = 0;
    
    set<int> s; // 현재 등장한 종류를 저장
    int curCnt = 0;
    for (int i = 0; i < topping.size(); i++) {
        // 아직 발견되지 않은 종류라면,
        if (s.find(topping[i]) == s.end()) {
            s.insert(topping[i]);
            curCnt++;
        }
        forwardgo[i] = curCnt;
    }
    
    s.clear();
    curCnt = 0;
    for (int i = topping.size() - 1; i >= 0; i--) {
        if (s.find(topping[i]) == s.end()) {
            s.insert(topping[i]);
            curCnt++;
        }
        backward[i] = curCnt;
    }
    
    for (int i = 0; i < topping.size() - 1; i++) {
        if (forwardgo[i] == backward[i + 1]) answer++;
    }
    
    return answer;
}