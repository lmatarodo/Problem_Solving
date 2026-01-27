#include <iostream>
#include <map>
#include <set>

using namespace std;

multimap<int, int> m; // 보석의 가격, 무게
multiset<int> s; // 가방의 무게

int main() {
    int n, k;
    cin >> n >> k;
    while (n--) {
        int price, weight;
        cin >> weight >> price;
        m.insert({price, weight}); // 오름차순 정렬
    }

    while (k--) {
        int maxWeight;
        cin >> maxWeight;
        s.insert(maxWeight);
    }

    long long ans = 0;
    auto cur = s.begin(); // 현재 가지고 있는 가방의 최소 무게
    for (auto it = m.rbegin(); it != m.rend(); it++) { // 가격이 큰 순서대로 내려옴
        auto bag = s.lower_bound(it->second); // 현재 보석을 담을 수 있는 가장 작은 가방의 무게
        if (bag == s.end()) continue; // 햔제 보석의 무게를 담을 수 있는 가방이 없음
        s.erase(bag); // 그 가방에 보석을 담았으므로 삭제함
        ans += it->first; // 담은 보석의 가격만큼 정답 변수를 올림
    }
    cout << ans;
    return 0;
}