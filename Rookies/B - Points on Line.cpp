#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Input number of points and maximum distance
    int n;
    long long d;
    cin >> n >> d;

    // Input coordinates of the points
    vector<long long> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }

    // Variable to store the number of valid triplets
    long long count = 0;

    // Use a two-pointer technique
    int left = 0;
    for (int right = 0; right < n; right++) {
        // Move the left pointer to ensure the distance condition
        while (points[right] - points[left] > d) {
            left++;
        }

        // Calculate the number of valid triplets using combinations
        long long num_points = right - left;
        if (num_points >= 2) {
            count += (num_points * (num_points - 1)) / 2;
        }
    }

    // Output the result
    cout << count << endl;

    return 0;
}
