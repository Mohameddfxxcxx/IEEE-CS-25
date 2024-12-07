#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n; // Number of students
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Input the programming skill of each student
    }

    sort(a.begin(), a.end()); // Sort the skills to allow sliding window logic

    int max_students = 0;
    int left = 0; // Left pointer for the sliding window

    for (int right = 0; right < n; right++) {
        // Check if the current window is valid
        while (a[right] - a[left] > 5) {
            left++; // Shrink the window from the left
        }
        // Update the maximum number of students in a balanced team
        max_students = max(max_students, right - left + 1);
    }

    cout << max_students << endl; // Output the result
    return 0;
}
