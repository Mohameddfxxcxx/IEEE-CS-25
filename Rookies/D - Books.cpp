#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Input the number of books and available free time
    int n;
    long long t;
    cin >> n >> t;

    // Input the time required for each book
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Sliding window approach
    int max_books = 0;  // Maximum number of books Valera can read
    long long current_time = 0;  // Current time spent
    int left = 0;  // Left pointer of the window

    for (int right = 0; right < n; right++) {
        current_time += a[right];  // Add the current book time

        // Shrink the window from the left if the total time exceeds t
        while (current_time > t) {
            current_time -= a[left];
            left++;
        }

        // Update the maximum number of books
        max_books = max(max_books, right - left + 1);
    }

    // Output the result
    cout << max_books << endl;

    return 0;
}
