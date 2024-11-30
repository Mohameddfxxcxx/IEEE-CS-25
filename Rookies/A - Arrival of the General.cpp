/*A - Arrival of the General*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);

    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int max_index = 0, min_index = 0;

    for (int i = 1; i < n; i++) {
        if (heights[i] > heights[max_index]) {
            max_index = i;
        }
        if (heights[i] <= heights[min_index]) {
            min_index = i;
        }
    }

    int swaps = max_index + (n - 1 - min_index);

    if (max_index > min_index) {
        swaps--;
    }

    cout << swaps << endl;

    return 0;
}
