#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

// Function to check if the current position is valid
bool isValid(int x, int y, int m, int n, const vector<string> &grid) {
    // Check if we're inside the bounds of the grid and at an oil pocket
    return x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '@';
}

// Function to perform BFS for a single oil deposit
void bfs(int x, int y, int m, int n, vector<string> &grid) {
    // Define possible moves in the grid (8 directions)
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    // Queue for BFS
    queue<pair<int, int>> q;
    q.push({x, y});
    grid[x][y] = '*'; // Mark the starting position as visited

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        // Check all adjacent positions
        for (int i = 0; i < 8; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            // If the new position is valid, add it to the queue and mark it visited
            if (isValid(nx, ny, m, n, grid)) {
                q.push({nx, ny});
                grid[nx][ny] = '*'; // Mark as visited
            }
        }
    }
}

int main() {
    ifstream inputFile("input.txt"); 
    ofstream outputFile("output.txt"); 

    int m, n;
    while (inputFile >> m >> n && m) { // Read grid dimensions
        vector<string> grid(m);
        for (int i = 0; i < m; i++) {
            inputFile >> grid[i]; // Read each row of the grid
        }

        int oilDeposits = 0; // Counter for oil deposits

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') { // Found an unvisited oil pocket
                    bfs(i, j, m, n, grid); // Perform BFS from this oil pocket
                    oilDeposits++; // Increase the count of oil deposits
                }
            }
        }

        outputFile << oilDeposits << endl; // Write the result to output file
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    return 0;
}
