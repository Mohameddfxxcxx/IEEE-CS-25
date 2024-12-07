#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t; // Number of books and available time
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Time required for each book
    }

    int max_books = 0; // Maximum number of books Valera can read
    int current_sum = 0; // Current sum of reading times in the sliding window
    int left = 0; // Left pointer of the sliding window

    for (int right = 0; right < n; right++) {
        current_sum += a[right]; // Add the current book's time

        // Shrink the window if the time exceeds the available time
        while (current_sum > t) {
            current_sum -= a[left];
            left++;
        }

        // Update the maximum number of books that can be read
        max_books = max(max_books, right - left + 1);
    }

    cout << max_books << endl;
    return 0;
}
