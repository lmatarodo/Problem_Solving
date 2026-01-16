#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 

    int N, M;
    cin >> N >> M;
    vector<long long> psum(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        long long x;
        cin >> x;
        psum[i] = psum[i - 1] + x;
    }

    while (M--) {
        int start, end;
        cin >> start >> end;
        
        cout << psum[end] - psum[start - 1] << "\n"; 
    }

    

}