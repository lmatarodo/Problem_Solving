#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int T, N;

int isInPlanet(vector<int>& planet, vector<int>& start, vector<int>& end) {
    int dist1, dist2;
    int result = 0;

    dist1 = sqrt(pow((planet.at(0) - start.at(0)), 2) + pow((planet.at(1) - start.at(1)), 2));
    dist2 = sqrt(pow((planet.at(0) - end.at(0)), 2) + pow((planet.at(1) - end.at(1)), 2));

    if (dist1 < planet.at(2) ^ dist2 < planet.at(2))
        result++;

    return result;
}

int main() {

    vector<int> planet(3);

    cin >> T;

    while (T--) {
        vector<int> start(2);
        vector<int> end(2);
        cin >> start[0] >> start[1] >> end[0] >> end[1];

        int total = 0;
        cin >> N;

        while (N--) {
            cin >> planet[0] >> planet[1] >> planet[2];
            total += isInPlanet(planet, start, end);
        }

        cout << total << "\n";
    }

    return 0;
}