#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

int calculateTime(const string& A, const string& B) { // 출차시간, 입차시간
    int Amin = stoi(A.substr(3, 2));
    int Bmin = stoi(B.substr(3, 2));
    int Ah = stoi(A.substr(0, 2));
    int Bh = stoi(B.substr(0, 2));
    
    int sum = 0;
    if (Amin < Bmin) {
        sum = (Ah - Bh - 1) * 60 + (60 - (Bmin - Amin));
    }
    else {
        sum = (Ah - Bh) * 60 + (Amin - Bmin);
    }
    return sum;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> m1; // 차량 번호, 총 주차 시간
    map<string, string> m2; // 차량 번호, 마지막 입차시간
    
    for (int i = 0; i < records.size(); i++) {
        if (records[i][11] == 'I') { // 입차인 경우
            string name = records[i].substr(6, 4);
            string time = records[i].substr(0, 5);
            m2[name] = time;
        }
        else if (records[i][11] == 'O') { // 출차인 경우
            string name = records[i].substr(6, 4);
            string time = records[i].substr(0, 5);
            auto it = m2.find(name);
            int parkingTime = calculateTime(time, it->second); // 출차시간, 입차시간
            m1[name] += parkingTime;
            m2.erase(name); 
        }
    }
    
    for (auto it : m2) { // 아직 입차시간이 남아있는 것들에 대해
        m1[it.first] += calculateTime("23:59", it.second);
    }
    
    for (auto it: m1) { // 총 요금 계산
        //cout << it.first << " " << it.second << "\n";
        if (it.second <= fees[0]) { // 기본 시간을 넘지 않음
            answer.push_back(fees[1]);
        }
        else { // 기본 시간을 넘음
            int total = fees[1] + ceil((double)(it.second - fees[0]) / fees[2]) * fees[3];
            answer.push_back(total);
        }
    }
    
    
    return answer;
}