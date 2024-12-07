#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n; // Number of chocolate bars
    vector<int> t(n);

    for (int i = 0; i < n; i++) {
        cin >> t[i]; // Time to eat each chocolate bar
    }

    int left = 0, right = n - 1; // Two pointers
    int timeAlice = 0, timeBob = 0; // Time spent by Alice and Bob
    int countAlice = 0, countBob = 0; // Bars consumed by Alice and Bob

    while (left <= right) {
        if (timeAlice <= timeBob) {
            // Alice eats the bar
            timeAlice += t[left];
            left++;
            countAlice++;
        } else {
            // Bob eats the bar
            timeBob += t[right];
            right--;
            countBob++;
        }
    }

    cout << countAlice << " " << countBob << endl;
    return 0;
}
