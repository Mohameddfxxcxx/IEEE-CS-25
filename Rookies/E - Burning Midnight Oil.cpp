#include <iostream>
using namespace std;

bool canWriteEnough(int v, int n, int k) {
    long long total = 0;
    long long current = v; // Current lines Vasya can write in one session
    while (current > 0) {
        total += current;
        if (total >= n) return true; // Early exit if total exceeds n
        current /= k;
    }
    return total >= n;
}

int main() {
    int n, k;
    cin >> n >> k;

    int left = 1, right = n, result = n;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canWriteEnough(mid, n, k)) {
            result = mid; // Update result
            right = mid - 1; // Try smaller v
        } else {
            left = mid + 1; // Try larger v
        }
    }

    cout << result << endl;

    return 0;
}
