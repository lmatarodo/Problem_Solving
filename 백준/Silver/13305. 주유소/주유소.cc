#include <iostream>

using namespace std;

int n;
int price[100002];
int dist[100002];

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) 
        cin >> dist[i];
    for (int i = 0; i < n; i++)
        cin >> price[i];

    
    int minPrice = price[0]; // 현재까지 나온 최솟값의 주유소
    int answer = price[0] * dist[0];
    for (int i = 1; i < n - 1; i++) {
        if (price[i] < minPrice) {
            minPrice = price[i];
        }
        answer += minPrice * dist[i];
    }

    cout << answer;    

}