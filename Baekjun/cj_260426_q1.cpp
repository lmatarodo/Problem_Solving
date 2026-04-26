#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX = 100000;

int solve(int n, int m) {

    int answer = 0;
    // 공통 작업: 에라토스테네스의 체로 소수 리스트 만들기
    vector<int> primes;
    vector<bool> isPrime(MAX + 1, true);
    isPrime[1] = false;

    for (int i = 2; i * i <= MAX; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= MAX; j += i) {
            isPrime[j] = false;
        }
    }

    for (int i = 1; i <= MAX; i++) {
        if (isPrime[i]) primes.push_back(i);
    }

    // n이 2일 때는 그냥 소수 반환,
    if (n == 2) {
        answer = primes[m - 1];
    }

    // n이 3일 때는 소수의 제곱 수 반환
    if (n == 3) {
        answer = pow(primes[m - 1], 2);
    }

    // n이 4일 때는 소수의 세제곱 혹은, 서로 다른 두 수의 곱이다.
    if (n == 4) {
        vector<int> candidate; // 답이 될 수 있는 숫자들을 담아놓는 배열

        for (int p: primes) {
            candidate.push_back(pow(p, 3));
        }

        for (int i = 0; i < primes.size(); i++) {
            for (int j = i + 1; j < primes.size(); j++) {
                long long val = (long long) primes[i] * primes[j];
                // 예상 범위를 넘어가면 일찍 종료 -> 최적화
                if (val > 1e9) break;
                candidate.push_back(val);
            }
            // 마찬가지로 예상 범위를 넘어가면 더 이상 검사할 필요가 없음
            if ((long long) primes[i] * primes[i + 1] > 1e9 && candidate.size() > m) break;
        }

        sort(candidate.begin(), candidate.end());
        answer = candidate[m - 1];
    }

    return answer;

}

int main() {

    int n, m;
    cin >> n >> m;
    cout << solve(n, m);
}