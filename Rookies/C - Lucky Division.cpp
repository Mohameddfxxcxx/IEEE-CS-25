/*C - Lucky Division*/
#include <iostream>
#include <vector>
using namespace std;

// Function to check if a number is lucky
bool isLucky(int number) {
    while (number > 0) {
        int digit = number % 10;
        if (digit != 4 && digit != 7) {
            return false; // If any digit is not 4 or 7, it's not lucky
        }
        number /= 10;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    // Generate all lucky numbers up to 1000
    vector<int> lucky_numbers;
    for (int i = 1; i <= 1000; i++) {
        if (isLucky(i)) {
            lucky_numbers.push_back(i);
        }
    }

    // Check if n is almost lucky
    bool is_almost_lucky = false;
    for (int lucky : lucky_numbers) {
        if (n % lucky == 0) {
            is_almost_lucky = true;
            break;
        }
    }

    // Output the result
    if (is_almost_lucky) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
