#include <string>
#include <vector>

using namespace std;

bool checkTime(long long time, int n, vector<int>& times) {
    
    long long count = 0;
    for (int t: times) {
        count += (time / t);
    }
    
    if (count >= n) return true;
    else return false;
}

long long solution(int n, vector<int> times) {
    long long answer = 1e14;
    
    long long left = 1;
    long long right = 1e14;
    
    while (left <= right) {
        long long mid = (left + right) / 2;
        
        if (checkTime(mid, n, times)) {
            answer = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;;
        }
    }
    return answer;
}