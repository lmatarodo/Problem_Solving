#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int v, e;
    // 비용, 정점1, 정점2
    tuple<int, int ,int> edge[1000005];
    // tuple의 비교는 제일 앞의 값부터 비교해서 채워짐, 따라서 비용 기준으로 오름차순 정렬
    sort(edge, edge + e); 

    int cnt = 0;
    for (int i = 0; i < e; i++) {
        int cost, a, b;
        // tie 함수: 여러개의 변수를 하나의 튜플로 묶어줌
        tie(cost, a, b) = edge[i];
        // 만약 두 정점이 같은 그룹이라면 그냥 넘어감
        if (!is_diff_group(a, b))continue;
        // 만약 두 정점이 다른 그룹이었다면, 간선을 출력한 뒤 cnt 1 증가
        cout << ' ' << a << ' ' << b;
        cnt++;
        // 만약 간선의 갯수가 v - 1개라면, 최소 신장 트리 완성
        if (cnt == v - 1) break;
    }



    return 0;
}