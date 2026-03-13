#include <string>
#include <vector>

using namespace std;

int solution(vector<string> board) {
    int answer = 1;
    int Ocnt = 0; int Xcnt = 0;
    bool Owin = false; bool Xwin = false;
    
    // 일단 O와 X의 갯수를 셈
    for (int i = 0;i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == 'O') Ocnt++;
            if (board[i][j] == 'X') Xcnt++;
        }
    }
    
    // O의 갯수가 X 갯수와 같지 않고 X갯수에서 1개 더한게 O 갯수와 같지 않음 두 상황 모두 포함되면 게임 성립 불가능
    if ((Ocnt != Xcnt) && (Ocnt != Xcnt + 1)) answer = 0;
    
    // 가로 방향으로 어느 누가 이겼는지 검사
    for (string line: board) {
        if (line == "OOO") Owin = true;
        if (line == "XXX") Xwin = true;
    }
    
    // 세로 방향으로 검사
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O') Owin = true;
        if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X') Xwin = true;
    }
    
    if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') Owin = true;
    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') Xwin = true;
    if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') Owin = true;
    if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') Xwin = true;
    
    if (Owin && Xwin) answer = 0; // 만약 둘다 이겼으면 성립 불가능
    
    if (Owin && (Ocnt != Xcnt + 1)) answer = 0;
    
    if (Xwin && (Ocnt != Xcnt)) answer = 0;
    
    return answer;
}