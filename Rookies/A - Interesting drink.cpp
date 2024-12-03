#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Input number of shops
    int n;
    cin >> n;

    // Input prices in the shops
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    // Sort the prices for efficient querying
    sort(prices.begin(), prices.end());

    // Input number of days
    int q;
    cin >> q;

    // Process each day's budget
    while (q--) {
        int mi;
        cin >> mi;

        // Find the number of shops where the drink is affordable
        int count = upper_bound(prices.begin(), prices.end(), mi) - prices.begin();
        cout << count << endl;
    }

    return 0;
}
