#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

int calculateTime(string inTime, string outTime) {
    int inHour = stoi(inTime.substr(0, 2)); 
    int outHour = stoi(outTime.substr(0, 2));
    int inMin = stoi(inTime.substr(3, 2));
    int outMin = stoi(outTime.substr(3, 2));
    
    int totalTime = 0;
    if (outMin >= inMin) {
        totalTime += (outMin - inMin);
        totalTime += (outHour - inHour) * 60;
        
    } else {
        totalTime += (60 - inMin + outMin);
        totalTime += (outHour - inHour - 1) * 60;
    }
    return totalTime;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<string, int> m1; // 차량번호, 주차시간
    map<string, string> m2; // 차량번호, 마지막 입차시간
    
    for (string record: records) {
        stringstream ss(record);
        string time, num, move;
        
        ss >> time >> num >> move;
        
        if (move == "IN") {
            m2[num] = time;
        }
        
        else if (move == "OUT") {
            string lastInTime = m2[num];
            int parkTime = calculateTime(lastInTime, time);
            m1[num] += parkTime;
            m2.erase(num);
        }
    }
    
    for (auto m: m2) {
        int parkTime = calculateTime(m.second, "23:59");
        m1[m.first] += parkTime;
    }
    
    for (auto m: m1) {
        if (m.second <= fees[0]) {
            answer.push_back(fees[1]);
        }
        else {
            int totalFee = fees[1];
            totalFee += ceil((double)(m.second - fees[0]) / fees[2]) * fees[3];
            answer.push_back(totalFee);
        }
    }
    
    return answer;
}