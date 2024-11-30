/*D - Launch of Collider*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    string directions;
    cin >> directions;

    vector<int> positions(n);
    for (int i = 0; i < n; ++i) {
        cin >> positions[i];
    }

    int min_time = INT_MAX;

    // Iterate through adjacent particles
    for (int i = 0; i < n - 1; ++i) {
        // Check for potential collision between i-th and (i+1)-th particle
        if (directions[i] == 'R' && directions[i + 1] == 'L') {
            int time = (positions[i + 1] - positions[i]) / 2;
            min_time = min(min_time, time);
        }
    }

    if (min_time == INT_MAX) {
        cout << -1 << endl; // No collision occurs
    } else {
        cout << min_time << endl; // Time of the first collision
    }

    return 0;
}
