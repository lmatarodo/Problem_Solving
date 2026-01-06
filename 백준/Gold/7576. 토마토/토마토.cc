#include <iostream>
#include <queue>
#define MAX_SIZE 1001

using namespace std;

struct tomato{
	int y, x;
};

int m, n, result;
queue<tomato> q;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int graph[MAX_SIZE][MAX_SIZE];

bool isInside(int ny, int nx) {
	return (0 <= nx && 0 <= ny && nx < m && ny < n);
}

void bfs(void) {
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (isInside(ny, nx) && graph[ny][nx] == 0) {
				graph[ny][nx] = graph[y][x] + 1;
				q.push({ ny,nx });
			}
		}
	}
}

int main() {
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 1) {
				q.push({ i, j });
			}
		}
	}

	bfs();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (graph[i][j] == 0) {
				cout << "-1";
				return 0;
			}

			if (result < graph[i][j]) {
				result = graph[i][j];
			}
		}
	}
	cout << result - 1;
	return 0;
}