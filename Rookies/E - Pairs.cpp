#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int pairs(int k, vector<int>& arr) {
    unordered_set<int> elements; // To store the elements of the array
    int count = 0;

    // Add all elements to the set
    for (int num : arr) {
        elements.insert(num);
    }

    // Check for each element if the complement (num ± k) exists
    for (int num : arr) {
        if (elements.count(num + k)) {
            count++;
        }
        if (elements.count(num - k)) {
            count++;
        }
        // Ensure we don't double-count pairs
        elements.erase(num);
    }

    return count;
}

int main() {
    int n, k;
    cin >> n >> k; // Input size of array and target difference
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Input array elements
    }

    cout << pairs(k, arr) << endl; // Output the result
    return 0;
}
