/*B - Police Recruits*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int untreated_crimes = 0;
    int available_officers = 0;

    for (int i = 0; i < n; i++) {
        int event;
        cin >> event;

        if (event == -1) { // A crime occurred
            if (available_officers > 0) {
                available_officers--; // Assign an officer to the crime
            } else {
                untreated_crimes++; // No officer available
            }
        } else { // Recruits hired
            available_officers += event;
        }
    }

    cout << untreated_crimes << endl;

    return 0;
}
