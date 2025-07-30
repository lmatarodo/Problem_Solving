#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int A, B, C;
    int resultNum;
    int resultStr;

    cin >> A >> B >> C;
    
    resultNum = A + B - C;
    cout << resultNum << "\n";

    int Bdigits = B;
    int digitCount = 0;
    
    while (Bdigits > 0) {
        digitCount ++;
        Bdigits /= 10;
    }

    resultStr = A * pow(10, digitCount) + B - C;
    cout << resultStr << "\n";

    return 0;
}

// '''
// 다른 풀이 방법
// string A, B, C 선언
// 문자열을 int 정수형으로 바꾸어주는 stoi 함수를 사용해서 덧셈과 뺄셈을 해줌

// iResult = (stoi(A) + stoi(B) - stoi(C));
// cResult = (stio(A + B) - stoi(C));
// '''
