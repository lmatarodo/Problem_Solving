#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), greater<int>());
    for (int i = 0; i <= citations.size(); i++) { // h-index 후보는 0부터 n-1
        int cnt = 0;
        for (int j = 0; j < citations.size(); j++) {
            if (citations[j] >= i) cnt++; // h-index 이상 인용되었다면 카운트 올림
        }
        if (i <= cnt) // 만약 최종 카운트가 h-index 이상이면, 정답 후보
            answer = max(answer, i);
    }
     
    return answer;
}