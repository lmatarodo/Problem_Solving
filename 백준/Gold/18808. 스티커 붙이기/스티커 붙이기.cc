#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
int board[42][42];
vector<vector<vector<int>>> stickers; // 스티커번호, 행, 열

void rotate(vector<vector<int>>& sticker) {

    int row = sticker.size();
    int col = sticker[0].size();

    vector<vector<int>> temp_sticker(col, vector<int>(row));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            temp_sticker[j][row - i - 1] = sticker[i][j];
        }
    }
    sticker = temp_sticker;

}

bool check(int x, int y, vector<vector<int>>& sticker) {
    int r = sticker.size();
    int c = sticker[0].size();

    if (x + r > n || y + c > m) return false;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (sticker[i][j] == 1 && board[x + i][y + j] == 1) return false;
        }
    }
    return true;
}

void attach(int x, int y, vector<vector<int>>& sticker) {
    for (int i = 0; i < sticker.size(); i++) {
        for (int j = 0; j < sticker[0].size(); j++) {
            if (sticker[i][j] == 1) board[x + i][y + j] = 1;
        }
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;

        vector<vector<int>> temp_sticker(r, vector<int>(c)); // 각 스티커를 입력으로 받을 임시 스티커 2차원벡터
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++) {
                cin >> temp_sticker[j][k];
            }
        }

        stickers.push_back(temp_sticker);
    }

    for (auto sticker: stickers) {
        
        bool isAttach = false;
        for (int dir = 0; dir < 4; dir++) {
            for (int i = 0; i <= n - (int)sticker.size(); i++) {
                for (int j = 0; j <= m - (int)sticker[0].size(); j++) {
                    if (check(i, j, sticker)) {
                        attach(i, j, sticker);
                        isAttach = true;
                        break;
                    }
                }
                if (isAttach) break;
            }
            if (isAttach) break;
            rotate(sticker);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1) ans++;
        }
    }
    cout << ans;

    return 0;
}
