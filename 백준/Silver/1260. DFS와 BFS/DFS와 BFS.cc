#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void dfs(int x, bool* y, vector<int>* z) {
	y[x] = true;
	cout << x << " ";
	for (int i = 0; i < z[x].size(); i++) {
		int j = z[x][i];
		if (!y[j]) {
			dfs(j, y, z);
		}
	}
}

void bfs(int start, bool* y, vector<int>* z) {
	queue<int> q;

	q.push(start);
	y[start] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << " ";

		for (int i = 0; i < z[x].size(); i++) {
			int j = z[x][i];
			if (!y[j]) {
				q.push(j);
				y[j] = true;
			}
		}
	}
}

int main() {
	int N, M, V; 
	cin >> N >> M >> V;

	bool* visited = new bool[N + 1];
	vector<int>* graph = new vector<int>[N + 1];

	fill(visited, visited + N + 1, false); // visited 배열 초기화

	for (int i = 1; i <= M; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		graph[num1].push_back(num2);
		graph[num2].push_back(num1);
	}

	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(V, visited, graph);

	cout << endl;
	fill(visited, visited + N + 1, false); // visited 배열 초기화

	bfs(V, visited, graph);

	delete[] visited;
	delete[] graph;
	return 0;
}