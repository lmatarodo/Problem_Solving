using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long solution(int w,int h) {
    long long answer = 1;
    
    long long W = w;
    long long H = h;
    long long g = gcd(W, H);
    answer = W * H - (W + H - g);    
    return answer;
}