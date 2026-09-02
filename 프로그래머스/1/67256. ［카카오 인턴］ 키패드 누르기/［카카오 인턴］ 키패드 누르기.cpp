#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<pair<int, int>> coord;
    coord.push_back({3, 1}); // 숫자 0의 좌표
    
    for (int num = 1; num <= 9; num++) {
        int r = (num - 1) / 3; int c = (num - 1) % 3;
        coord.push_back({r, c});
    }
    
    pair<int, int> left = {3, 0};
    pair<int, int> right = {3, 2}; // 양손의 이전 위치를 기억
    for (int num: numbers) {
        if (num == 1 || num == 4 || num == 7) {
            answer += "L";
            left = {coord[num].first, coord[num].second};
        }
        
        else if (num == 3 || num == 6 || num == 9) {
            answer += "R";
            right = {coord[num].first, coord[num].second};
        }
        
        else {
            
            pair<int, int> curcoord = {coord[num].first, coord[num].second};
            int leftLength = abs(left.first - curcoord.first) + abs(left.second - curcoord.second);
            int rightLength = abs(right.first - curcoord.first) + abs(right.second - curcoord.second);
            
            if (leftLength == rightLength) {
                if (hand == "left") {
                    answer += "L";
                    left = {coord[num].first, coord[num].second};
                }

                else { 
                    answer += "R";
                    right = {coord[num].first, coord[num].second};
                }
            }
            
            else if (leftLength > rightLength) {
                right = {coord[num].first, coord[num].second};
                answer += "R";
            }
            
            else {
                answer += "L";
                left = {coord[num].first, coord[num].second};
            }
        }
    }
    
    return answer;
}