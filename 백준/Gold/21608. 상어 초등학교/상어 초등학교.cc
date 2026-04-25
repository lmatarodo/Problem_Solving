#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
int classroom[22][22];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void solve(int personNum, vector<vector<int>>& favorite) {
    int maxFavorite = -1;
    int maxEmpty = -1;
    int bestR = -1, bestC = -1;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (classroom[r][c] != 0) continue;
            
            int favoriteCnt = 0;
            int emptyCnt = 0;

            for (int dir = 0; dir < 4; dir++) {
                int nx = r + dx[dir];
                int ny = c + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                
                if (classroom[nx][ny] == 0) emptyCnt++;
                else {
                    for (int i = 0; i < 4; i++) {
                        if (favorite[personNum][i] == classroom[nx][ny]) {
                            favoriteCnt++;
                            break;
                        }
                    }
                }
                
            }

            if (favoriteCnt > maxFavorite) {
                maxFavorite = favoriteCnt;
                maxEmpty = emptyCnt;
                bestR = r;
                bestC = c;
            }
            
            else if (favoriteCnt == maxFavorite) {
                if (emptyCnt > maxEmpty) {
                    maxEmpty = emptyCnt;
                    bestR = r;
                    bestC = c;
                }
            }
        }
    }

    classroom[bestR][bestC] = personNum;
}

int scoreCal(vector<vector<int>>& favorite) {

    int totalScore = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            int personNum = classroom[r][c];
            int favoriteCnt = 0;

            for (int dir = 0; dir < 4; dir++) {
                int nx = r + dx[dir];
                int ny = c + dy[dir];
                
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                for (int i = 0; i < 4; i++) {
                    if (classroom[nx][ny] == favorite[personNum][i]){
                        favoriteCnt++;
                        break;
                    }
                }
            }

            if (favoriteCnt == 0) continue;
            totalScore += pow(10, favoriteCnt - 1);
        }
    }

    return totalScore;
}

int main() {
    cin >> n;

    vector<vector<int>> favorite(n * n + 1, vector<int>(4, 0));
    vector<int> order;
    int personNum;

    for (int i = 0; i < n * n; i++) {
        cin >> personNum;
        order.push_back(personNum);
        for (int j = 0; j < 4; j++) 
            cin >> favorite[personNum][j];
    }

    for (int i = 0; i < n * n; i++){
        solve(order[i], favorite);
    }
    cout << scoreCal(favorite);

    return 0;
}
