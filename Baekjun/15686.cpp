#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int city[52][52];
vector<pair<int, int>> house; // 집 인덱스 저장
vector<pair<int, int>> chicken; // 치킨집 인덱스 저장
vector<int> selected; // 선택된 치킨집의 인덱스 저장
int answer = 1e9;

int calculate() { // m개의 선택된 치킨집을 기반으로 도시의 치킨거리를 계산
    int city_dist = 0;
    for (auto h: house) {
        int min_dist = 1e9;
        for (int idx: selected) {
            int d = abs(h.first - chicken[idx].first) + abs(h.second - chicken[idx].second);
            if (d < min_dist) min_dist = d;
        }
        city_dist += min_dist;
    }
    return city_dist;
}

void findCombination(int idx, int cnt) { // 치킨집 중에서 m개의 집을 고르는 함수
    if (cnt == m) {
        answer = min(answer, calculate());
        return;
    }

    for (int i = idx; i < chicken.size(); i++) {
        selected.push_back(i);
        findCombination(i + 1, cnt + 1);
        selected.pop_back();
    }

}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> city[i][j];
            if (city[i][j] == 1) house.push_back({i, j});
            else if (city[i][j] == 2) chicken.push_back({i, j});
        }
    }
    findCombination(0, 0);
    cout << answer;

    return 0;
}