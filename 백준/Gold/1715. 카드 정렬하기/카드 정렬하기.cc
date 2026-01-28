#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main() {
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq; // 최소 힙

    int num;
    while (n--) { 
        cin >> num;
        pq.push(num);
    }

    int ans = 0;
    while (pq.size() > 1) { // 뭉치가 2개 이상일 때만 합치기 수행
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        int sum = first + second;
        ans += sum;
        pq.push(sum);
    }   

    cout << ans;
    
    return 0;
}