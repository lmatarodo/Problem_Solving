#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[200]; // 컴퓨터 노드를 방문했는지 여부

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    queue<int> q;
    
    for (int i = 0; i < n; i++) {         
        if (computers[i][i] == 1 && !visited[i]){
            q.push(i);
            visited[i] = true;
            
            while (!q.empty()){
                int curr = q.front(); // 현재 컴퓨터 인덱스
                q.pop();
                
                for (int j = 0; j < n; j++) {
                    if (computers[curr][j] == 1 && !visited[j]) {
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
            answer++;
        }
        
    }
    
    return answer;
}