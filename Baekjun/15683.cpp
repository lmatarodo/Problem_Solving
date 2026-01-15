#include <iostream>

using namespace std;

int n, m;
char arr[8][8];

struct CCTV {
    int x, y, type;
};
vector<CCTV> cctvs;

void dfs(int index) {
    char backup[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            backup[i][j] = arr[i][j];
        }
    }

    if (index == cctvs.size()) {
        
        return;
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != '0' && arr[i][j] != '6') { // CCTV를 만나면,

            }
        }
    }



    return 0;
}