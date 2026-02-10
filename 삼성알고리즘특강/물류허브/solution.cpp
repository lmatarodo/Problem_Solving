#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

#define INF 1e9
#define MAX_V 3000

struct Edge {
    int to;
    int cost;
};

struct Node {
    int id;
    int dist;
    bool operator> (const Node& other) const{
        return dist > other.dist;
    }
};

unordered_map<int, int> cityMap;
vector<Edge> adj[MAX_V];
vector<Edge> rev_adj[MAX_V];
int cityCount;

// cityMap에서 id를 찾고 없으면 새로운 인덱스 부여 후 cityCount 증가
int getCityIndex(int id) {
    if (cityMap.find(id) == cityMap.end()) {
        cityMap[id] = cityCount++;
    }
    return cityMap[id];
}

int init(int N, int sCity[], int eCity[], int mCost[]) {

    cityMap.clear();
    cityCount = 0;

    for (int i = 0; i < MAX_V; i++) {
        adj[i].clear();
        rev_adj[i].clear();
    }

    for (int i = 0; i < N; i++) {
        int u = getCityIndex(sCity[i]);
        int v = getCityIndex(eCity[i]);
        adj[u].push_back({v, mCost[i]});
        rev_adj[v].push_back({u, mCost[i]});
    }

	return cityCount;
}

void add(int sCity, int eCity, int mCost) {

    int u = getCityIndex(sCity);
    int v = getCityIndex(eCity);
    adj[u].push_back({v, mCost});
    rev_adj[v].push_back({u, mCost});

}

void dijkstra(int start, vector<Edge> graph[], int dist[]) {
    for (int i = 0; i < cityCount; i++) dist[i] = INF;
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    dist[start] = 0;
    pq.push({start, 0});

    while (!pq.empty()) {
        Node curr = pq.top(); pq.pop();
        
        if (dist[curr.id] < curr.dist) continue;

        for (auto& edge: graph[curr.id]) {
            if (dist[edge.to] > dist[curr.id] + edge.cost) {
                dist[edge.to] = dist[curr.id] + edge.cost;
                pq.push({edge.to, dist[edge.to]});
            }
        }
    }
}

int cost(int mHub) {
    int hubIdx = cityMap[mHub];
    int distTo[MAX_V];
    int distFrom[MAX_V];

    dijkstra(hubIdx, adj, distTo);
    dijkstra(hubIdx, rev_adj, distFrom);

    int totalCost = 0;
    for (int i = 0; i < cityCount; i++) {
        if (i == hubIdx) continue;
        totalCost += (distTo[i] + distFrom[i]);
    }

	return totalCost;
}