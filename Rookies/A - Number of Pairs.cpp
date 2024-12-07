#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to count pairs with sum in the range [L, R]
long long countPairs(vector<int>& a, int l, int r) {
    sort(a.begin(), a.end()); // Sort the array
    long long count = 0;
    int n = a.size();

    for (int i = 0; i < n; i++) {
        // Find the lower bound of the range
        int low = lower_bound(a.begin() + i + 1, a.end(), l - a[i]) - a.begin();
        // Find the upper bound of the range
        int high = upper_bound(a.begin() + i + 1, a.end(), r - a[i]) - a.begin() - 1;
        // Count pairs in the range
        if (low <= high) {
            count += (high - low + 1);
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << countPairs(a, l, r) << endl;
    }
    return 0;
}
