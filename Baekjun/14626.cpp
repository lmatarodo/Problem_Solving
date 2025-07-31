#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main() {
    int isbnNum[13] = { 0, };
    int whereLostNum = 0;
    string isbn;
    cin >> isbn;

    int isbnCount = 0;
    for (int i = 0; i < isbn.length() ; i++) {
        if(isdigit(isbn.at(i))) {
            isbnNum[isbnCount] = isbn.at(i) - '0'; //문자를 숫자형으로 변환
            isbnCount++;
        }
        else {
            whereLostNum = i;
            isbnNum[isbnCount] = 0; //문자를 숫자형으로 변환
            isbnCount++;
        }
    }

    if (whereLostNum == 12) {
        int sum = 0;
        for (int i = 0; i < isbn.length() - 1; i++) {
            if (i % 2 == 0) {
                sum += isbnNum[i];
            }
            else {
                sum += 3 * isbnNum[i];
            }
        }
        isbnNum[whereLostNum] = 10 - (sum % 10);
        if (isbnNum[whereLostNum] == 10) {
            cout << "0" << "\n";
        } 
        else {
            cout << isbnNum[whereLostNum] << "\n"; 
        }
    }

    else if (whereLostNum % 2 == 0) {
        int sum = 0;
        int checkNum = 10 - isbnNum[12];

        for (int i = 0; i < isbn.length() - 1; i++) {
            if (i != whereLostNum && i % 2 == 0) {
                sum += isbnNum[i];
            }
            else if (i != whereLostNum && i % 2 == 1) {
                sum += 3 * isbnNum[i];
            }
        }
        for (int i = 1; i <= 10; i++) {
            if ( (i + sum) % 10 == checkNum) {
                if (i == 10) {
                    cout << "0" << "\n";
                }
                else {
                    cout << i << "\n";
                }
            }

        }
    }

    else if(whereLostNum % 2 == 1) {
        int sum = 0;
        int checkNum = (10 - isbnNum[12])% 10; // 여기에서 0~9 사이의 값만 나오게 했어야 했음!!

        for (int i = 0; i < isbn.length() - 1; i++) {
            if (i != whereLostNum && i % 2 == 0) {
                sum += isbnNum[i];
            }
            else if (i != whereLostNum && i % 2 == 1) {
                sum += 3 * isbnNum[i];
            }
        }
        for (int i = 1; i <= 10; i++) {
            if ( (i * 3 + sum) % 10 == checkNum) {
                if (i == 10) {
                    cout << "0" << "\n";
                }
                else {
                    cout << i << "\n";
                }           
            }

        }
    }

    return 0;
}