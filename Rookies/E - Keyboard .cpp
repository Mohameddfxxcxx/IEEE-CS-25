/*E - Keyboard*/
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    // Define the keyboard layout
    string row1 = "qwertyuiop";
    string row2 = "asdfghjkl;";
    string row3 = "zxcvbnm,./";

    // Store the keyboard layout in a map
    unordered_map<char, char> shiftLeft, shiftRight;

    // Populate the maps for shifting
    for (int i = 1; i < row1.size(); ++i) {
        shiftLeft[row1[i]] = row1[i - 1];
        shiftRight[row1[i - 1]] = row1[i];
    }
    for (int i = 1; i < row2.size(); ++i) {
        shiftLeft[row2[i]] = row2[i - 1];
        shiftRight[row2[i - 1]] = row2[i];
    }
    for (int i = 1; i < row3.size(); ++i) {
        shiftLeft[row3[i]] = row3[i - 1];
        shiftRight[row3[i - 1]] = row3[i];
    }

    // Read input
    char direction;
    string typed;
    cin >> direction >> typed;

    string result = "";

    // Translate the typed message to the original message
    for (char ch : typed) {
        if (direction == 'R') {
            result += shiftLeft[ch];
        } else if (direction == 'L') {
            result += shiftRight[ch];
        }
    }

    // Output the original message
    cout << result << endl;

    return 0;
}
