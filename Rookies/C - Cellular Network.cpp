#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    // Input the number of cities and towers
    int n, m;
    cin >> n >> m;

    // Input city coordinates
    vector<long long> cities(n);
    for (int i = 0; i < n; i++) {
        cin >> cities[i];
    }

    // Input tower coordinates
    vector<long long> towers(m);
    for (int i = 0; i < m; i++) {
        cin >> towers[i];
    }

    // Two-pointer approach to find minimal radius
    int j = 0; // Pointer for towers
    long long max_r = 0; // Maximum radius required

    for (int i = 0; i < n; i++) {
        // Move the tower pointer to the closest position for the current city
        while (j < m - 1 && abs(towers[j + 1] - cities[i]) <= abs(towers[j] - cities[i])) {
            j++;
        }
        // Update the maximum radius needed to cover this city
        max_r = max(max_r, abs(towers[j] - cities[i]));
    }

    // Output the result
    cout << max_r << endl;

    return 0;
}
