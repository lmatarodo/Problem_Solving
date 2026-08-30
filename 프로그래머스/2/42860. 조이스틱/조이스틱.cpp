#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    
    for (int i = 0; i < name.size(); i++) {
        answer += min('Z' - name[i] + 1, name[i] - 'A');
    }
    
    int n = name.size();
    int move = n - 1;
    for (int i = 0; i < n; i++) {
        int next = i + 1;
        
        while (next < n && name[next] == 'A') {
            next++;
        }
        
        int right = 2 * i + (n - next);
        int left = 2 * (n - next) + i;
        
        move = min({move, right, left});
    }
    answer += move;
    
    return answer;
}