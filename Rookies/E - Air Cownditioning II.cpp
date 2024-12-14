#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Cow {
    int start, end, cooling;
};

struct AirConditioner {
    int start, end, power, cost;
};

bool canCoolAllCows(const vector<Cow>& cows, const vector<AirConditioner>& airConditioners, int mask) {
    vector<int> cooling(101, 0);

    // Apply cooling from the selected air conditioners
    for (int i = 0; i < airConditioners.size(); i++) {
        if (mask & (1 << i)) { // If the i-th air conditioner is chosen
            for (int j = airConditioners[i].start; j <= airConditioners[i].end; j++) {
                cooling[j] += airConditioners[i].power;
            }
        }
    }

    // Check if all cows are satisfied
    for (const auto& cow : cows) {
        for (int j = cow.start; j <= cow.end; j++) {
            if (cooling[j] < cow.cooling) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<Cow> cows(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i].start >> cows[i].end >> cows[i].cooling;
    }

    vector<AirConditioner> airConditioners(M);
    for (int i = 0; i < M; i++) {
        cin >> airConditioners[i].start >> airConditioners[i].end >> airConditioners[i].power >> airConditioners[i].cost;
    }

    int minCost = INT_MAX;

    // Try all subsets of air conditioners (2^M possible subsets)
    for (int mask = 0; mask < (1 << M); mask++) {
        if (canCoolAllCows(cows, airConditioners, mask)) {
            int cost = 0;
            for (int i = 0; i < M; i++) {
                if (mask & (1 << i)) {
                    cost += airConditioners[i].cost;
                }
            }
            minCost = min(minCost, cost);
        }
    }

    cout << minCost << endl;
    return 0;
}
