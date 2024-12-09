#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <climits>

using namespace std;

class ChessKnight {
private:
    // Defining all 8 possible knight moves
    vector<pair<int, int>> directions = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                                         {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    // Helper function to convert chess board notation (like "a1") to matrix coordinates
    pair<int, int> chessToIndex(const string& pos) {
        return {pos[0] - 'a', pos[1] - '1'};
    }

    // Helper function to check if the given position is within the bounds of the chessboard
    bool isValid(int x, int y) {
        return x >= 0 && x < 8 && y >= 0 && y < 8;
    }

public:
    // Function to calculate the minimum number of moves from start to destination
    int minMoves(const string& start, const string& dest) {
        // If start and destination are the same, no move is required
        if (start == dest) return 0;

        pair<int, int> startPos = chessToIndex(start);
        pair<int, int> destPos = chessToIndex(dest);

        queue<pair<int, int>> q;
        map<pair<int, int>, int> visited;  // To store the number of moves to reach each square

        q.push(startPos);
        visited[startPos] = 0;

        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();

            // Explore all possible moves
            for (auto& move : directions) {
                int newX = current.first + move.first;
                int newY = current.second + move.second;

                if (isValid(newX, newY)) {
                    pair<int, int> newPos = {newX, newY};

                    // If the destination is reached, return the number of moves
                    if (newPos == destPos) {
                        return visited[current] + 1;
                    }

                    // If the position is not visited, mark it as visited and add it to the queue
                    if (visited.find(newPos) == visited.end()) {
                        visited[newPos] = visited[current] + 1;
                        q.push(newPos);
                    }
                }
            }
        }

        // If no path is found (although for this problem, there always should be one)
        return -1;
    }
};

int main() {
    int T;
    cin >> T;

    ChessKnight knight;

    while (T--) {
        string start, dest;
        cin >> start >> dest;

        // Get the minimum number of moves
        int result = knight.minMoves(start, dest);
        cout << result << endl;
    }

    return 0;
}
